#ifndef INCLUDE_TRAITS_HPP_
#define INCLUDE_TRAITS_HPP_

#include <boost/random/normal_distribution.hpp>
#include <boost/math/distributions/normal.hpp>

#include <boost/random/uniform_smallint.hpp>

#include <boost/random/poisson_distribution.hpp>
#include <boost/math/distributions/poisson.hpp>

#include <boost/random/uniform_real_distribution.hpp>

#include <boost/math/constants/constants.hpp>

#include "distr/min_max_discrete.hpp"
#include "distr/vmf.hpp"

#include "flatbuffers/infcomp_generated.h"

namespace cpprob {
namespace detail {

template<typename IntType = int, typename WeightType = double>
min_max_discrete_distribution<IntType, WeightType>
get_min_max_discrete(const infcomp::ProposalReply* msg)
{
    auto param = static_cast<const infcomp::UniformDiscrete*>(msg->distribution());
    flatbuffers::Vector<double>::iterator probs_ptr = param->proposal_probabilities()->data()->begin();
    return min_max_discrete_distribution<IntType, WeightType>(param->prior_min(),
                                                              param->prior_min() + param->prior_size() - 1,
                                                              probs_ptr, probs_ptr+param->prior_size());
}

} // end namespace detail

template <class RealType>
RealType pdf(const boost::random::normal_distribution<RealType>& distr,
             const typename boost::random::normal_distribution<RealType>::result_type & x)
{
    using namespace boost::math;
    return pdf(normal_distribution<RealType>{distr.mean(), distr.sigma()}, x);
}

template <class IntType>
double pdf(const boost::random::uniform_smallint<IntType>& distr,
           const typename boost::random::uniform_smallint<IntType>::result_type &)
{
    return 1.0/(distr.max() - distr.min() + 1.0);
}

template<class IntType, class WeightType>
WeightType pdf(const min_max_discrete_distribution<IntType, WeightType>& dist,
               const typename min_max_discrete_distribution<IntType, WeightType>::result_type & x)
{
    if (x < dist.min() || x > dist.max()) return 0;
    return dist.probabilities()[static_cast<std::size_t>(x-dist.min())];
}

template<class RealType>
RealType pdf(const vmf_distribution<RealType>& distr,
             const typename vmf_distribution<RealType>::result_type & x)
{
    if (distr.kappa() == 0){
        return 1.0/(4.0 * boost::math::constants::pi<RealType>());
    }
    return 0;

}

template<typename IntType, class RealType>
IntType pdf(const boost::random::poisson_distribution<IntType, RealType>& distr,
             const typename boost::random::poisson_distribution<IntType, RealType>::result_type & x)
{
    using namespace boost::math;
    return pdf(poisson_distribution<RealType>(distr.mean()), x);
}

template<typename RealType = double>
RealType pdf(const boost::random::uniform_real_distribution<RealType>& distr,
            const typename boost::random::uniform_real_distribution<RealType>::result_type &)
{
    return 1/(distr.b()-distr.a());
}

template <class RealType>
boost::random::normal_distribution<>::param_type default_type_param(const boost::random::normal_distribution<RealType>& distr)
{
    return boost::random::normal_distribution<>::param_type(static_cast<double>(distr.mean()),
                                                            static_cast<double>(distr.sigma()));
}

template <class IntType>
boost::random::uniform_smallint<>::param_type default_type_param(const boost::random::uniform_smallint<IntType>& distr)
{
    return boost::random::uniform_smallint<>::param_type(static_cast<int>(distr.a()),
                                                         static_cast<int>(distr.b()));
}

template<class RealType>
vmf_distribution<>::param_type default_type_param(const vmf_distribution<RealType>& distr)
{
    auto mu = distr.mu();
    std::vector<double> mu_double(mu.begin(), mu.end());
    return vmf_distribution<>::param_type(mu_double, distr.kappa());
}

template<class IntType, class RealType>
boost::random::poisson_distribution<>::param_type default_type_param(const boost::random::poisson_distribution<IntType, RealType>& distr)
{
    return boost::random::poisson_distribution<>::param_type(static_cast<double>(distr.mean()));
}

template<class RealType>
boost::random::uniform_real_distribution<>::param_type default_type_param(const boost::random::uniform_real_distribution<RealType>& distr)
{
    return boost::random::uniform_real_distribution<>::param_type(static_cast<double>(distr.a()), static_cast<double>(distr.b()));
}

template<template <class ...> class Distr, class ...Params>
struct proposal { };

template<class RealType>
struct proposal<boost::random::normal_distribution, RealType> {
    static constexpr auto type_enum = infcomp::Distribution::Normal;

    static boost::random::normal_distribution<RealType>
    get_distr(const infcomp::ProposalReply* msg)
    {
        auto param = static_cast<const infcomp::Normal*>(msg->distribution());
        return boost::random::normal_distribution<RealType>(param->proposal_mean(), param->proposal_std());
    }
};


template<class IntType>
struct proposal<boost::random::uniform_smallint, IntType> {
    static constexpr auto type_enum = infcomp::Distribution::UniformDiscrete;

    template<class RealType = double>
    static min_max_discrete_distribution<IntType, RealType>
    get_distr(const infcomp::ProposalReply* msg)
    {
        return detail::get_min_max_discrete<IntType, RealType>(msg);
    }
};

template<class RealType>
struct proposal<vmf_distribution, RealType> {
    static constexpr auto type_enum = infcomp::Distribution::VMF;

    static vmf_distribution<RealType>
    get_distr(const infcomp::ProposalReply* msg)
    {
        auto distr = static_cast<const infcomp::VMF*>(msg->distribution());
        flatbuffers::Vector<double>::iterator mu_ptr = distr->proposal_mu()->data()->begin();
        auto dim = distr->proposal_mu()->data()->size();
        return vmf_distribution<RealType>(mu_ptr, mu_ptr + dim, distr->proposal_kappa());
    }
};

template<class RealType>
struct proposal<boost::random::uniform_real_distribution, RealType> {
    static constexpr auto type_enum = infcomp::Distribution::UniformContinuous;

    static boost::random::uniform_real_distribution<RealType>
    get_distr(const infcomp::ProposalReply* msg)
    {
        auto distr = static_cast<const infcomp::UniformContinuous*>(msg->distribution());
        return boost::random::uniform_real_distribution<RealType>(distr->prior_min(), distr->prior_max());
    }
};

template<class IntType, class RealType>
struct proposal<boost::random::poisson_distribution, IntType, RealType> {
    static constexpr auto type_enum = infcomp::Distribution::Poisson;

    static boost::random::poisson_distribution<IntType, RealType>
    get_distr(const infcomp::ProposalReply* msg)
    {
        auto distr = static_cast<const infcomp::Poisson*>(msg->distribution());
        return boost::random::poisson_distribution<IntType, RealType>(distr->proposal_lambda());
    }
};

template<class RealType>
constexpr infcomp::Distribution proposal<boost::random::normal_distribution, RealType>::type_enum;

template<class RealType>
constexpr infcomp::Distribution proposal<vmf_distribution, RealType>::type_enum;

template<class IntType>
constexpr infcomp::Distribution proposal<boost::random::uniform_smallint, IntType>::type_enum;

template<class RealType>
constexpr infcomp::Distribution proposal<boost::random::uniform_real_distribution, RealType>::type_enum;

template<class IntType, class RealType>
constexpr infcomp::Distribution proposal<boost::random::poisson_distribution, IntType, RealType>::type_enum;
}  // end namespace cpprob
#endif  // INCLUDE_TRAITS_HPP_
