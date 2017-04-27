#ifndef INCLUDE_NDARRAY_HPP
#define INCLUDE_NDARRAY_HPP

#include <vector>
#include <algorithm>
#include <type_traits>
#include <stdexcept>
#include <iostream>
#include <numeric>
#include <functional>

#include "cpprob/detail/vector_io.hpp"

namespace cpprob {

template<class T = double>
class NDArray {
public:
    NDArray() = default;

    NDArray(T a) : values_{a}, shape_{1} {}

    template<class U,
            class = std::enable_if_t <std::is_constructible<T, U>::value>>
    NDArray(U a) : NDArray(T(a)) {}

    template<class U>
    NDArray(const std::vector <U> &v)
    {
        compute_shape(v, 0);
        values_ = flatten(v, 0);
    }

    NDArray& operator+=(const NDArray & rhs)
    {
        if (this->shape().empty()){
            *this = rhs;
            return *this;
        }
        if (rhs.shape_.empty())
            return *this;
        if (this->shape() != rhs.shape())
            throw std::domain_error("The tensors do not have the same shape");

        std::transform(values_.begin(),
                       values_.end(),
                       rhs.values_.begin(),
                       values_.begin(),
                       std::plus<double>());
        return *this;
    }

    NDArray& operator*=(const double rhs)
    {
        std::transform(values_.begin(),
                       values_.end(),
                       values_.begin(),
                       [rhs](double a){ return rhs * a; });
        return *this;
    }

    NDArray& operator/=(const double rhs)
    {

        std::transform(values_.begin(),
                       values_.end(),
                       values_.begin(),
                       [rhs](double a){ return a / rhs; });
        return *this;
    }

    // friend functions
    friend NDArray operator+ (const NDArray& lhs, const NDArray& rhs){ return NDArray(lhs) += rhs; }
    friend NDArray operator* (const double lhs, const NDArray& rhs){ return NDArray(rhs) *= lhs; }
    friend NDArray operator* (const NDArray& lhs, const double rhs){ return NDArray(lhs) *= rhs; }

    template<class CharT, class Traits>
    friend std::basic_ostream< CharT, Traits > &
    operator<<(std::basic_ostream< CharT, Traits > & os, const NDArray & v) {
        if (v.shape_.size() == 1 && v.shape_[0] == 1) {
            os << v.values_[0];
            return os;
        }

        detail::print_vector(os, v.values_);

        if (v.shape_.size() != 1) {
            os << os.widen(' ');
            detail::print_vector(os, v.shape_);
        }
        return os;
    }

    std::vector <T> values() const
    {
        return values_;
    }

    std::vector <int> shape() const
    {
        return shape_;
    }

private:
    template<class U,
            class = std::enable_if_t <std::is_constructible<T, U>::value>>
    void compute_shape(const std::vector <U> &v, int i)
    {
        if (static_cast<int>(shape_.size()) <= i)
            shape_.emplace_back(v.size());
        else if (shape_[i] < static_cast<int>(v.size()))
            shape_[i] = v.size();
    }

    // i is the dimension that we are processing
    template<class U>
    void compute_shape(const std::vector<std::vector<U>> & v, int i)
    {
        if (static_cast<int>(shape_.size()) <= i)
            shape_.emplace_back(v.size());
        else if (static_cast<int>(v.size()) > shape_[i])
            shape_[i] = v.size();
        for (const auto& e : v)
            compute_shape(e, i+1);
    }

    template<class U,
            class = std::enable_if_t <std::is_constructible<T, U>::value>>
    std::vector <T> flatten(const std::vector <U> &v, int)
    {
        auto ret = v;
        ret.resize(shape_.back());
        return std::vector<T>(std::make_move_iterator(ret.begin()), std::make_move_iterator(ret.end()));
    }

    template<class U>
    auto flatten(const std::vector <std::vector<U>> &v, int i)
    {
        auto size_tensor_i = std::accumulate(shape_.begin()+i, shape_.end(), 1, std::multiplies<int>());

        decltype(flatten(v.front(), i+1)) ret;
        for (const auto &e : v) {
            auto init_e = flatten(e, i+1);
            ret.insert(ret.end(), std::make_move_iterator(init_e.begin()), std::make_move_iterator(init_e.end()));
        }
        ret.resize(size_tensor_i);
        return ret;
    }

    std::vector <T> values_;
    std::vector <int> shape_;
};
} // end namespace cpprob
#endif //INCLUDE_NDARRAY_HPP