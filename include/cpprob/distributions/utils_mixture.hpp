#ifndef CPPROB_UTILS_MIXTURE_HPP
#define CPPROB_UTILS_MIXTURE_HPP

#include <algorithm> // inner product
#include <cmath>

// Include necessary to specify MixtureNormal in flatbuffers
#include <boost/random/normal_distribution.hpp>

#include "cpprob/distributions/mixture.hpp"
#include "cpprob/distributions/utils_base.hpp"

namespace cpprob {

namespace detail {

template<class F, class Distribution, class RealType>
RealType map(const mixture<Distribution, RealType> & distr, const F & f) {
    const auto coefs = distr.coefficients();
    const auto distributions = distr.distributions();
    return std::inner_product(coefs.begin(), coefs.end(),
                              distributions.begin(), RealType{0},
                              std::plus<RealType>(),
                              [&f](RealType c, const Distribution &d) { return c * f(d); });
}
} // end namespace detail

//////////////////////////////
////////// Proposal //////////
//////////////////////////////

template<typename Distribution, class RealType>
struct logpdf<mixture<Distribution, RealType>> {
    RealType operator()(const mixture<Distribution, RealType>& distr,
                        const typename mixture<Distribution, RealType>::result_type & x) const
    {
        // logsumexp for log(coef) + logpdf(distributions). Maybe use the more stable version of the algorithm
        return std::log(detail::map(distr,
                           [&x](const Distribution & distribution) {
                               return std::exp(logpdf<Distribution>()(distribution, x));
                           }));
    }
};

template<class Distribution, class RealType>
struct buffer<mixture<Distribution, RealType>> {
    using type = protocol::Mixture;
};

template<class Distribution, class RealType>
struct from_flatbuffers<mixture<Distribution, RealType>> {
    using distr_t = mixture<Distribution, RealType>;

    distr_t operator()(const buffer_t<distr_t> * distr) {
        std::vector<Distribution> v_distr(distr->distributions()->size());
        auto distr_fbb = distr->distributions()->begin();
        for (auto & distr_i : v_distr) {
            distr_i = from_flatbuffers<Distribution>()(distr_fbb->template distribution_as<buffer_t<Distribution>>());
            ++distr_fbb;
        }
        return distr_t(distr->coefficients()->begin(), distr->coefficients()->end(),
                       v_distr.begin(), v_distr.end());
    }
};

//////////////////////////////
///////// Truncated  /////////
//////////////////////////////

template<class Distribution, class RealType>
struct normalise<mixture<Distribution, RealType>> {

    RealType operator()(const mixture<Distribution, RealType> & distr,
                        typename Distribution::result_type min,
                        typename Distribution::result_type max)
    {
        return detail::map(distr,
                           [min, max](const Distribution & d){
                               return normalise<Distribution>()(d, min, max);
                           });
    }
};
} // end namespace cpprob

#endif //CPPROB_UTILS_MIXTURE_HPP
