#ifndef CPPROB_UTILS_MULTIVARIATE_NORMAL_HPP
#define CPPROB_UTILS_MULTIVARIATE_NORMAL_HPP

#include <cmath>
#include <type_traits>
#include <vector>

#include "cpprob/distributions/utils_base.hpp"
#include "cpprob/distributions/multivariate_normal.hpp"
#include "cpprob/distributions/utils_normal_distribution.hpp" // logpdf(normal)
#include "cpprob/ndarray.hpp"
#include "flatbuffers/infcomp_generated.h"

namespace cpprob {

//////////////////////////////
////// Prior & Proposal //////
//////////////////////////////

template<typename RealType>
struct logpdf<multivariate_normal_distribution<RealType>> {
    RealType operator()(const multivariate_normal_distribution<RealType>& distr,
                        const typename multivariate_normal_distribution<RealType>::result_type & x) const
    {
        RealType ret = 0;
        auto vec_distr = distr.distr();
        auto it_distr = vec_distr.begin();
        auto it_x = x.begin();
        for(; it_distr != vec_distr.end() && it_x != x.end(); ++it_distr, ++it_x)
            ret += logpdf<std::decay_t<decltype(*it_distr)>>()(*it_distr, *it_x);
        return ret;
    }
};

template<class RealType>
struct buffer<multivariate_normal_distribution<RealType>> {
    using type = protocol::MultivariateNormal;
};

//////////////////////////////
/////////// Prior  ///////////
//////////////////////////////

template<class RealType>
struct proposal<multivariate_normal_distribution<RealType>> {
    using type = multivariate_normal_distribution<RealType>;
};

template<class RealType>
struct to_flatbuffers<multivariate_normal_distribution<RealType>> {
    using distr_t = multivariate_normal_distribution<RealType>;

    flatbuffers::Offset<void> operator()(flatbuffers::FlatBufferBuilder& buff,
                                         const distr_t & distr,
                                         const typename distr_t::result_type & value)
    {
        auto mean = distr.mean();
        return protocol::CreateMultivariateNormal(buff,
                protocol::CreateNDArray(buff,
                    buff.CreateVector<double>(mean.values()),
                    buff.CreateVector<int32_t>(mean.shape_int())),
                buff.CreateVector<double>(distr.covariance()),
                protocol::CreateNDArray(buff,
                    buff.CreateVector<double>(value.values()),
                    buff.CreateVector<int32_t>(value.shape_int()))
        ).Union();
    }
};

//////////////////////////////
///////// Proposal  //////////
//////////////////////////////

template<class RealType>
struct from_flatbuffers<multivariate_normal_distribution<RealType>> {
    using distr_t = multivariate_normal_distribution<RealType>;

    distr_t operator()(const buffer_t<distr_t> * distr) {
        auto mean = NDArray<double>(
                std::vector<double>(distr->mean()->data()->begin(), distr->mean()->data()->end()),
                std::vector<std::size_t>(distr->mean()->shape()->begin(), distr->mean()->shape()->end()));

        return distr_t(std::move(mean), distr->covariance()->begin(), distr->covariance()->end());
    }
};

} // end namespace cpprob

#endif //CPPROB_UTILS_MULTIVARIATE_NORMAL_HPP
