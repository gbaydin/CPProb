#ifndef CPPROB_METAPRIORS_HPP_
#define CPPROB_METAPRIORS_HPP_

#include <cpprob/utils.hpp>
#include <cpprob/traits.hpp>

namespace cpprob {

template<template<class> class Derived, class ResultType>
struct MetaDistribution {
    template<class RNG>
    ResultType operator()(RNG &rng) { return Derived<ResultType>::distr(rng); }
};

template<class ResultType=double>
struct MetaNormal : MetaDistribution<MetaNormal, ResultType> {
    static constexpr ResultType mean = 0;
    static constexpr ResultType std = 1;
    static std::normal_distribution<ResultType> distr;
};
template<class ResultType>
std::normal_distribution<ResultType> MetaNormal<ResultType>::distr{mean, std};

template<class ResultType=int>
struct MetaPoisson : MetaDistribution<MetaPoisson, ResultType> {
    static constexpr double mean = 2;
    static std::poisson_distribution<ResultType> distr;
};
template<class ResultType>
std::poisson_distribution<ResultType> MetaPoisson<ResultType>::distr{mean};

template<class T, class MetaDistr>
class Prior {
public:
    Prior() : t_(meta_distr(get_rng())) {}

    Prior(const T &t) : t_{t} {}

    operator T() const { return t_; }

    MetaDistr meta_distr{};
    T t_;
};

namespace detail {

template<class T>
struct RemPrior {
    using type = T;
};
template<class T, class U>
struct RemPrior<Prior<T, U>> {
    using type = T;
};
template<class T>
struct RemPrior<T &> {
    using type = typename RemPrior<T>::type &;
};
template<class T>
struct RemPrior<T &&> {
    using type = typename RemPrior<T>::type &&;
};
template<class T>
struct RemPrior<const T> {
    using type = typename RemPrior<T>::type const;
};
template<class T>
struct RemPrior<volatile T> {
    using type = typename RemPrior<T>::type volatile;
};
template<template<typename...> class TT, class... Ts>
struct RemPrior<TT<Ts...>> {
    using type = TT<typename RemPrior<Ts>::type...>;
};

template<template<typename...> class TT, class... Ts>
std::enable_if_t<
        is_iterable<TT<Ts...>>::value,
        typename RemPrior<TT<Ts...>>::type>
rem_prior(TT<Ts...> &&a);

template<template<typename...> class TT, class... Ts>
std::enable_if_t<
        !is_iterable<TT<Ts...>>::value &&
        is_tuple_like<TT<Ts...>>::value,
        typename RemPrior<TT<Ts...>>::type>
rem_prior(TT<Ts...> &&a);

template<template<typename...> class TT, class... Ts>
std::enable_if_t<
        !is_iterable<TT<Ts...>>::value &&
        !is_tuple_like<TT<Ts...>>::value,
        typename RemPrior<TT<Ts...>>::type>
rem_prior(TT<Ts...> &&a);

template<class T, class U>
typename RemPrior<T>::type rem_prior(Prior<T, U> &&a);

template<class T>
T rem_prior(T &&a) {
    return a;
}

template<class T, class U>
typename RemPrior<T>::type rem_prior(Prior<T, U> &&a) {
    auto ret = rem_prior(std::move(a.t_));
    return ret;
}

template<template<typename...> class TT, class... Ts>
std::enable_if_t<
        is_iterable<TT<Ts...>>::value,
        typename RemPrior<TT<Ts...>>::type>
rem_prior(TT<Ts...> &&a) {
    typename RemPrior<TT<Ts...>>::type ret;
    std::transform(std::make_move_iterator(begin(a)),
                   std::make_move_iterator(end(a)),
                   std::back_inserter(ret),
                   [](auto e) { return rem_prior(e); });
    return ret;
}

using std::get;
using std::tuple_size;

template<template<typename...> class TT, class... Ts, std::size_t... Indices>
auto rem_prior_tuple(TT<Ts...> &&tup, std::index_sequence<Indices...>) {
    return TT<Ts...>{rem_prior(std::move(get<Indices>(tup)))...};
}

template<template<typename...> class TT, class... Ts>
std::enable_if_t<
        !is_iterable<TT<Ts...>>::value &&
        is_tuple_like<TT<Ts...>>::value,
        typename RemPrior<TT<Ts...>>::type>
rem_prior(TT<Ts...> &&a) {
    return detail::rem_prior_tuple(std::move(a), std::make_index_sequence<tuple_size<TT<Ts...>>::value>());
}

template<template<typename...> class TT, class... Ts>
std::enable_if_t<
        !is_iterable<TT<Ts...>>::value &&
        !is_tuple_like<TT<Ts...>>::value,
        typename RemPrior<TT<Ts...>>::type>
rem_prior(TT<Ts...> &&a) {
    return TT<typename RemPrior<Ts>::type...>(std::move(a));
}

template <class Tuple, class Indices> struct remove_last_impl;
template <class Tuple, std::size_t... I>
struct remove_last_impl<Tuple, std::index_sequence<I...>> {
    using type = std::tuple<typename std::tuple_element<I, Tuple>::type...>;
};

template <class Tuple>
using remove_last  = typename remove_last_impl<Tuple, std::make_index_sequence<std::tuple_size<Tuple>::value - 1>>::type;

} // end namespace detail

template<class... Types>
struct Builder {
    using types = std::tuple<Types...>;
};

template<class T>
std::true_type has_builder_impl(Builder<T>);
std::false_type has_builder_impl(...);

template<class F>
using has_builder = decltype(has_builder_impl(std::declval<last_elem<parameter_types_t<F>>>()));

template<class F>
using tuple_observes_t = std::conditional_t<has_builder<F>::value,
                                            detail::remove_last<parameter_types_t<F>>,
                                            parameter_types_t<F>>;


template<class... Args, std::size_t... Indices>
auto discard_last(const std::tuple<Args...> &args, std::index_sequence<Indices...>)
{
    return std::make_tuple(std::get<Indices>(args)...);
}

template<class... Args>
auto discard_build_impl(const std::tuple<Args...>& args, std::true_type)
{
    return discard_last(args, std::make_index_sequence<sizeof...(Args) -1>{});
}

template<class... Args>
auto discard_build_impl(const std::tuple<Args...>& args, std::false_type)
{
    return args;
}

template<class... Args>
auto discard_build(const std::tuple<Args...>& args)
{
    return discard_build_impl(args, decltype(has_builder_impl(
                                             std::declval<last_elem<std::tuple<Args...>>>()
                                            )){});
}

} // end namespace cpprob
#endif //CPPROB_METAPRIORS_HPP_