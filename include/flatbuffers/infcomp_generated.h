// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_INFCOMP_INFCOMP_H_
#define FLATBUFFERS_GENERATED_INFCOMP_INFCOMP_H_

#include "flatbuffers/flatbuffers.h"

namespace infcomp {

struct Message;

struct NDArray;

struct Categorical;

struct Discrete;

struct Flip;

struct Normal;

struct UniformDiscrete;

struct VMF;

struct Sample;

struct Trace;

struct TracesFromPriorRequest;

struct TracesFromPriorReply;

struct ObservesInitRequest;

struct ObservesInitReply;

struct ProposalRequest;

struct ProposalReply;

enum class MessageBody : uint8_t {
  NONE = 0,
  TracesFromPriorRequest = 1,
  ObservesInitRequest = 2,
  ProposalRequest = 3,
  TracesFromPriorReply = 4,
  ObservesInitReply = 5,
  ProposalReply = 6,
  MIN = NONE,
  MAX = ProposalReply
};

inline const char **EnumNamesMessageBody() {
  static const char *names[] = {
    "NONE",
    "TracesFromPriorRequest",
    "ObservesInitRequest",
    "ProposalRequest",
    "TracesFromPriorReply",
    "ObservesInitReply",
    "ProposalReply",
    nullptr
  };
  return names;
}

inline const char *EnumNameMessageBody(MessageBody e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesMessageBody()[index];
}

template<typename T> struct MessageBodyTraits {
  static const MessageBody enum_value = MessageBody::NONE;
};

template<> struct MessageBodyTraits<TracesFromPriorRequest> {
  static const MessageBody enum_value = MessageBody::TracesFromPriorRequest;
};

template<> struct MessageBodyTraits<ObservesInitRequest> {
  static const MessageBody enum_value = MessageBody::ObservesInitRequest;
};

template<> struct MessageBodyTraits<ProposalRequest> {
  static const MessageBody enum_value = MessageBody::ProposalRequest;
};

template<> struct MessageBodyTraits<TracesFromPriorReply> {
  static const MessageBody enum_value = MessageBody::TracesFromPriorReply;
};

template<> struct MessageBodyTraits<ObservesInitReply> {
  static const MessageBody enum_value = MessageBody::ObservesInitReply;
};

template<> struct MessageBodyTraits<ProposalReply> {
  static const MessageBody enum_value = MessageBody::ProposalReply;
};

bool VerifyMessageBody(flatbuffers::Verifier &verifier, const void *obj, MessageBody type);
bool VerifyMessageBodyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

enum class Distribution : uint8_t {
  NONE = 0,
  Categorical = 1,
  Discrete = 2,
  Flip = 3,
  Normal = 4,
  UniformDiscrete = 5,
  VMF = 6,
  MIN = NONE,
  MAX = VMF
};

inline const char **EnumNamesDistribution() {
  static const char *names[] = {
    "NONE",
    "Categorical",
    "Discrete",
    "Flip",
    "Normal",
    "UniformDiscrete",
    "VMF",
    nullptr
  };
  return names;
}

inline const char *EnumNameDistribution(Distribution e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesDistribution()[index];
}

template<typename T> struct DistributionTraits {
  static const Distribution enum_value = Distribution::NONE;
};

template<> struct DistributionTraits<Categorical> {
  static const Distribution enum_value = Distribution::Categorical;
};

template<> struct DistributionTraits<Discrete> {
  static const Distribution enum_value = Distribution::Discrete;
};

template<> struct DistributionTraits<Flip> {
  static const Distribution enum_value = Distribution::Flip;
};

template<> struct DistributionTraits<Normal> {
  static const Distribution enum_value = Distribution::Normal;
};

template<> struct DistributionTraits<UniformDiscrete> {
  static const Distribution enum_value = Distribution::UniformDiscrete;
};

template<> struct DistributionTraits<VMF> {
  static const Distribution enum_value = Distribution::VMF;
};

bool VerifyDistribution(flatbuffers::Verifier &verifier, const void *obj, Distribution type);
bool VerifyDistributionVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Message FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_BODY_TYPE = 4,
    VT_BODY = 6
  };
  MessageBody body_type() const {
    return static_cast<MessageBody>(GetField<uint8_t>(VT_BODY_TYPE, 0));
  }
  const void *body() const {
    return GetPointer<const void *>(VT_BODY);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_BODY_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_BODY) &&
           VerifyMessageBody(verifier, body(), body_type()) &&
           verifier.EndTable();
  }
};

struct MessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_body_type(MessageBody body_type) {
    fbb_.AddElement<uint8_t>(Message::VT_BODY_TYPE, static_cast<uint8_t>(body_type), 0);
  }
  void add_body(flatbuffers::Offset<void> body) {
    fbb_.AddOffset(Message::VT_BODY, body);
  }
  MessageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MessageBuilder &operator=(const MessageBuilder &);
  flatbuffers::Offset<Message> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Message>(end);
    return o;
  }
};

inline flatbuffers::Offset<Message> CreateMessage(
    flatbuffers::FlatBufferBuilder &_fbb,
    MessageBody body_type = MessageBody::NONE,
    flatbuffers::Offset<void> body = 0) {
  MessageBuilder builder_(_fbb);
  builder_.add_body(body);
  builder_.add_body_type(body_type);
  return builder_.Finish();
}

struct NDArray FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_DATA = 4,
    VT_SHAPE = 6
  };
  const flatbuffers::Vector<double> *data() const {
    return GetPointer<const flatbuffers::Vector<double> *>(VT_DATA);
  }
  const flatbuffers::Vector<int32_t> *shape() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_SHAPE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_DATA) &&
           verifier.Verify(data()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SHAPE) &&
           verifier.Verify(shape()) &&
           verifier.EndTable();
  }
};

struct NDArrayBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_data(flatbuffers::Offset<flatbuffers::Vector<double>> data) {
    fbb_.AddOffset(NDArray::VT_DATA, data);
  }
  void add_shape(flatbuffers::Offset<flatbuffers::Vector<int32_t>> shape) {
    fbb_.AddOffset(NDArray::VT_SHAPE, shape);
  }
  NDArrayBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NDArrayBuilder &operator=(const NDArrayBuilder &);
  flatbuffers::Offset<NDArray> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<NDArray>(end);
    return o;
  }
};

inline flatbuffers::Offset<NDArray> CreateNDArray(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<double>> data = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> shape = 0) {
  NDArrayBuilder builder_(_fbb);
  builder_.add_shape(shape);
  builder_.add_data(data);
  return builder_.Finish();
}

inline flatbuffers::Offset<NDArray> CreateNDArrayDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<double> *data = nullptr,
    const std::vector<int32_t> *shape = nullptr) {
  return infcomp::CreateNDArray(
      _fbb,
      data ? _fbb.CreateVector<double>(*data) : 0,
      shape ? _fbb.CreateVector<int32_t>(*shape) : 0);
}

struct Categorical FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PRIOR_SIZE = 4,
    VT_PROPOSAL_PROBABILITIES = 6
  };
  int32_t prior_size() const {
    return GetField<int32_t>(VT_PRIOR_SIZE, 0);
  }
  const NDArray *proposal_probabilities() const {
    return GetPointer<const NDArray *>(VT_PROPOSAL_PROBABILITIES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_PRIOR_SIZE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROPOSAL_PROBABILITIES) &&
           verifier.VerifyTable(proposal_probabilities()) &&
           verifier.EndTable();
  }
};

struct CategoricalBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_prior_size(int32_t prior_size) {
    fbb_.AddElement<int32_t>(Categorical::VT_PRIOR_SIZE, prior_size, 0);
  }
  void add_proposal_probabilities(flatbuffers::Offset<NDArray> proposal_probabilities) {
    fbb_.AddOffset(Categorical::VT_PROPOSAL_PROBABILITIES, proposal_probabilities);
  }
  CategoricalBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CategoricalBuilder &operator=(const CategoricalBuilder &);
  flatbuffers::Offset<Categorical> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Categorical>(end);
    return o;
  }
};

inline flatbuffers::Offset<Categorical> CreateCategorical(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t prior_size = 0,
    flatbuffers::Offset<NDArray> proposal_probabilities = 0) {
  CategoricalBuilder builder_(_fbb);
  builder_.add_proposal_probabilities(proposal_probabilities);
  builder_.add_prior_size(prior_size);
  return builder_.Finish();
}

struct Discrete FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PRIOR_SIZE = 4,
    VT_PROPOSAL_PROBABILITIES = 6
  };
  int32_t prior_size() const {
    return GetField<int32_t>(VT_PRIOR_SIZE, 0);
  }
  const NDArray *proposal_probabilities() const {
    return GetPointer<const NDArray *>(VT_PROPOSAL_PROBABILITIES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_PRIOR_SIZE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROPOSAL_PROBABILITIES) &&
           verifier.VerifyTable(proposal_probabilities()) &&
           verifier.EndTable();
  }
};

struct DiscreteBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_prior_size(int32_t prior_size) {
    fbb_.AddElement<int32_t>(Discrete::VT_PRIOR_SIZE, prior_size, 0);
  }
  void add_proposal_probabilities(flatbuffers::Offset<NDArray> proposal_probabilities) {
    fbb_.AddOffset(Discrete::VT_PROPOSAL_PROBABILITIES, proposal_probabilities);
  }
  DiscreteBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DiscreteBuilder &operator=(const DiscreteBuilder &);
  flatbuffers::Offset<Discrete> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Discrete>(end);
    return o;
  }
};

inline flatbuffers::Offset<Discrete> CreateDiscrete(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t prior_size = 0,
    flatbuffers::Offset<NDArray> proposal_probabilities = 0) {
  DiscreteBuilder builder_(_fbb);
  builder_.add_proposal_probabilities(proposal_probabilities);
  builder_.add_prior_size(prior_size);
  return builder_.Finish();
}

struct Flip FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PROPOSAL_PROBABILITY = 4
  };
  double proposal_probability() const {
    return GetField<double>(VT_PROPOSAL_PROBABILITY, 0.0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_PROPOSAL_PROBABILITY) &&
           verifier.EndTable();
  }
};

struct FlipBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_proposal_probability(double proposal_probability) {
    fbb_.AddElement<double>(Flip::VT_PROPOSAL_PROBABILITY, proposal_probability, 0.0);
  }
  FlipBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  FlipBuilder &operator=(const FlipBuilder &);
  flatbuffers::Offset<Flip> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<Flip>(end);
    return o;
  }
};

inline flatbuffers::Offset<Flip> CreateFlip(
    flatbuffers::FlatBufferBuilder &_fbb,
    double proposal_probability = 0.0) {
  FlipBuilder builder_(_fbb);
  builder_.add_proposal_probability(proposal_probability);
  return builder_.Finish();
}

struct Normal FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PRIOR_MEAN = 4,
    VT_PRIOR_STD = 6,
    VT_PROPOSAL_MEAN = 8,
    VT_PROPOSAL_STD = 10
  };
  double prior_mean() const {
    return GetField<double>(VT_PRIOR_MEAN, 0.0);
  }
  double prior_std() const {
    return GetField<double>(VT_PRIOR_STD, 0.0);
  }
  double proposal_mean() const {
    return GetField<double>(VT_PROPOSAL_MEAN, 0.0);
  }
  double proposal_std() const {
    return GetField<double>(VT_PROPOSAL_STD, 0.0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_PRIOR_MEAN) &&
           VerifyField<double>(verifier, VT_PRIOR_STD) &&
           VerifyField<double>(verifier, VT_PROPOSAL_MEAN) &&
           VerifyField<double>(verifier, VT_PROPOSAL_STD) &&
           verifier.EndTable();
  }
};

struct NormalBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_prior_mean(double prior_mean) {
    fbb_.AddElement<double>(Normal::VT_PRIOR_MEAN, prior_mean, 0.0);
  }
  void add_prior_std(double prior_std) {
    fbb_.AddElement<double>(Normal::VT_PRIOR_STD, prior_std, 0.0);
  }
  void add_proposal_mean(double proposal_mean) {
    fbb_.AddElement<double>(Normal::VT_PROPOSAL_MEAN, proposal_mean, 0.0);
  }
  void add_proposal_std(double proposal_std) {
    fbb_.AddElement<double>(Normal::VT_PROPOSAL_STD, proposal_std, 0.0);
  }
  NormalBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NormalBuilder &operator=(const NormalBuilder &);
  flatbuffers::Offset<Normal> Finish() {
    const auto end = fbb_.EndTable(start_, 4);
    auto o = flatbuffers::Offset<Normal>(end);
    return o;
  }
};

inline flatbuffers::Offset<Normal> CreateNormal(
    flatbuffers::FlatBufferBuilder &_fbb,
    double prior_mean = 0.0,
    double prior_std = 0.0,
    double proposal_mean = 0.0,
    double proposal_std = 0.0) {
  NormalBuilder builder_(_fbb);
  builder_.add_proposal_std(proposal_std);
  builder_.add_proposal_mean(proposal_mean);
  builder_.add_prior_std(prior_std);
  builder_.add_prior_mean(prior_mean);
  return builder_.Finish();
}

struct UniformDiscrete FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PRIOR_MIN = 4,
    VT_PRIOR_SIZE = 6,
    VT_PROPOSAL_PROBABILITIES = 8
  };
  int32_t prior_min() const {
    return GetField<int32_t>(VT_PRIOR_MIN, 0);
  }
  int32_t prior_size() const {
    return GetField<int32_t>(VT_PRIOR_SIZE, 0);
  }
  const NDArray *proposal_probabilities() const {
    return GetPointer<const NDArray *>(VT_PROPOSAL_PROBABILITIES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_PRIOR_MIN) &&
           VerifyField<int32_t>(verifier, VT_PRIOR_SIZE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROPOSAL_PROBABILITIES) &&
           verifier.VerifyTable(proposal_probabilities()) &&
           verifier.EndTable();
  }
};

struct UniformDiscreteBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_prior_min(int32_t prior_min) {
    fbb_.AddElement<int32_t>(UniformDiscrete::VT_PRIOR_MIN, prior_min, 0);
  }
  void add_prior_size(int32_t prior_size) {
    fbb_.AddElement<int32_t>(UniformDiscrete::VT_PRIOR_SIZE, prior_size, 0);
  }
  void add_proposal_probabilities(flatbuffers::Offset<NDArray> proposal_probabilities) {
    fbb_.AddOffset(UniformDiscrete::VT_PROPOSAL_PROBABILITIES, proposal_probabilities);
  }
  UniformDiscreteBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  UniformDiscreteBuilder &operator=(const UniformDiscreteBuilder &);
  flatbuffers::Offset<UniformDiscrete> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<UniformDiscrete>(end);
    return o;
  }
};

inline flatbuffers::Offset<UniformDiscrete> CreateUniformDiscrete(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t prior_min = 0,
    int32_t prior_size = 0,
    flatbuffers::Offset<NDArray> proposal_probabilities = 0) {
  UniformDiscreteBuilder builder_(_fbb);
  builder_.add_proposal_probabilities(proposal_probabilities);
  builder_.add_prior_size(prior_size);
  builder_.add_prior_min(prior_min);
  return builder_.Finish();
}

struct VMF FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PRIOR_MU = 4,
    VT_PRIOR_KAPPA = 6,
    VT_PROPOSAL_MU = 8,
    VT_PROPOSAL_KAPPA = 10
  };
  const NDArray *prior_mu() const {
    return GetPointer<const NDArray *>(VT_PRIOR_MU);
  }
  double prior_kappa() const {
    return GetField<double>(VT_PRIOR_KAPPA, 0.0);
  }
  const NDArray *proposal_mu() const {
    return GetPointer<const NDArray *>(VT_PROPOSAL_MU);
  }
  double proposal_kappa() const {
    return GetField<double>(VT_PROPOSAL_KAPPA, 0.0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PRIOR_MU) &&
           verifier.VerifyTable(prior_mu()) &&
           VerifyField<double>(verifier, VT_PRIOR_KAPPA) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROPOSAL_MU) &&
           verifier.VerifyTable(proposal_mu()) &&
           VerifyField<double>(verifier, VT_PROPOSAL_KAPPA) &&
           verifier.EndTable();
  }
};

struct VMFBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_prior_mu(flatbuffers::Offset<NDArray> prior_mu) {
    fbb_.AddOffset(VMF::VT_PRIOR_MU, prior_mu);
  }
  void add_prior_kappa(double prior_kappa) {
    fbb_.AddElement<double>(VMF::VT_PRIOR_KAPPA, prior_kappa, 0.0);
  }
  void add_proposal_mu(flatbuffers::Offset<NDArray> proposal_mu) {
    fbb_.AddOffset(VMF::VT_PROPOSAL_MU, proposal_mu);
  }
  void add_proposal_kappa(double proposal_kappa) {
    fbb_.AddElement<double>(VMF::VT_PROPOSAL_KAPPA, proposal_kappa, 0.0);
  }
  VMFBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VMFBuilder &operator=(const VMFBuilder &);
  flatbuffers::Offset<VMF> Finish() {
    const auto end = fbb_.EndTable(start_, 4);
    auto o = flatbuffers::Offset<VMF>(end);
    return o;
  }
};

inline flatbuffers::Offset<VMF> CreateVMF(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<NDArray> prior_mu = 0,
    double prior_kappa = 0.0,
    flatbuffers::Offset<NDArray> proposal_mu = 0,
    double proposal_kappa = 0.0) {
  VMFBuilder builder_(_fbb);
  builder_.add_proposal_kappa(proposal_kappa);
  builder_.add_prior_kappa(prior_kappa);
  builder_.add_proposal_mu(proposal_mu);
  builder_.add_prior_mu(prior_mu);
  return builder_.Finish();
}

struct Sample FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TIME = 4,
    VT_ADDRESS = 6,
    VT_INSTANCE = 8,
    VT_DISTRIBUTION_TYPE = 10,
    VT_DISTRIBUTION = 12,
    VT_VALUE = 14
  };
  int32_t time() const {
    return GetField<int32_t>(VT_TIME, 0);
  }
  const flatbuffers::String *address() const {
    return GetPointer<const flatbuffers::String *>(VT_ADDRESS);
  }
  int32_t instance() const {
    return GetField<int32_t>(VT_INSTANCE, 0);
  }
  Distribution distribution_type() const {
    return static_cast<Distribution>(GetField<uint8_t>(VT_DISTRIBUTION_TYPE, 0));
  }
  const void *distribution() const {
    return GetPointer<const void *>(VT_DISTRIBUTION);
  }
  const NDArray *value() const {
    return GetPointer<const NDArray *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_TIME) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_ADDRESS) &&
           verifier.Verify(address()) &&
           VerifyField<int32_t>(verifier, VT_INSTANCE) &&
           VerifyField<uint8_t>(verifier, VT_DISTRIBUTION_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_DISTRIBUTION) &&
           VerifyDistribution(verifier, distribution(), distribution_type()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_VALUE) &&
           verifier.VerifyTable(value()) &&
           verifier.EndTable();
  }
};

struct SampleBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_time(int32_t time) {
    fbb_.AddElement<int32_t>(Sample::VT_TIME, time, 0);
  }
  void add_address(flatbuffers::Offset<flatbuffers::String> address) {
    fbb_.AddOffset(Sample::VT_ADDRESS, address);
  }
  void add_instance(int32_t instance) {
    fbb_.AddElement<int32_t>(Sample::VT_INSTANCE, instance, 0);
  }
  void add_distribution_type(Distribution distribution_type) {
    fbb_.AddElement<uint8_t>(Sample::VT_DISTRIBUTION_TYPE, static_cast<uint8_t>(distribution_type), 0);
  }
  void add_distribution(flatbuffers::Offset<void> distribution) {
    fbb_.AddOffset(Sample::VT_DISTRIBUTION, distribution);
  }
  void add_value(flatbuffers::Offset<NDArray> value) {
    fbb_.AddOffset(Sample::VT_VALUE, value);
  }
  SampleBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  SampleBuilder &operator=(const SampleBuilder &);
  flatbuffers::Offset<Sample> Finish() {
    const auto end = fbb_.EndTable(start_, 6);
    auto o = flatbuffers::Offset<Sample>(end);
    return o;
  }
};

inline flatbuffers::Offset<Sample> CreateSample(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t time = 0,
    flatbuffers::Offset<flatbuffers::String> address = 0,
    int32_t instance = 0,
    Distribution distribution_type = Distribution::NONE,
    flatbuffers::Offset<void> distribution = 0,
    flatbuffers::Offset<NDArray> value = 0) {
  SampleBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_distribution(distribution);
  builder_.add_instance(instance);
  builder_.add_address(address);
  builder_.add_time(time);
  builder_.add_distribution_type(distribution_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Sample> CreateSampleDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t time = 0,
    const char *address = nullptr,
    int32_t instance = 0,
    Distribution distribution_type = Distribution::NONE,
    flatbuffers::Offset<void> distribution = 0,
    flatbuffers::Offset<NDArray> value = 0) {
  return infcomp::CreateSample(
      _fbb,
      time,
      address ? _fbb.CreateString(address) : 0,
      instance,
      distribution_type,
      distribution,
      value);
}

struct Trace FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_OBSERVES = 4,
    VT_SAMPLES = 6
  };
  const NDArray *observes() const {
    return GetPointer<const NDArray *>(VT_OBSERVES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Sample>> *samples() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Sample>> *>(VT_SAMPLES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBSERVES) &&
           verifier.VerifyTable(observes()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SAMPLES) &&
           verifier.Verify(samples()) &&
           verifier.VerifyVectorOfTables(samples()) &&
           verifier.EndTable();
  }
};

struct TraceBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_observes(flatbuffers::Offset<NDArray> observes) {
    fbb_.AddOffset(Trace::VT_OBSERVES, observes);
  }
  void add_samples(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Sample>>> samples) {
    fbb_.AddOffset(Trace::VT_SAMPLES, samples);
  }
  TraceBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TraceBuilder &operator=(const TraceBuilder &);
  flatbuffers::Offset<Trace> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Trace>(end);
    return o;
  }
};

inline flatbuffers::Offset<Trace> CreateTrace(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<NDArray> observes = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Sample>>> samples = 0) {
  TraceBuilder builder_(_fbb);
  builder_.add_samples(samples);
  builder_.add_observes(observes);
  return builder_.Finish();
}

inline flatbuffers::Offset<Trace> CreateTraceDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<NDArray> observes = 0,
    const std::vector<flatbuffers::Offset<Sample>> *samples = nullptr) {
  return infcomp::CreateTrace(
      _fbb,
      observes,
      samples ? _fbb.CreateVector<flatbuffers::Offset<Sample>>(*samples) : 0);
}

struct TracesFromPriorRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NUM_TRACES = 4
  };
  int32_t num_traces() const {
    return GetField<int32_t>(VT_NUM_TRACES, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_NUM_TRACES) &&
           verifier.EndTable();
  }
};

struct TracesFromPriorRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_num_traces(int32_t num_traces) {
    fbb_.AddElement<int32_t>(TracesFromPriorRequest::VT_NUM_TRACES, num_traces, 0);
  }
  TracesFromPriorRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TracesFromPriorRequestBuilder &operator=(const TracesFromPriorRequestBuilder &);
  flatbuffers::Offset<TracesFromPriorRequest> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<TracesFromPriorRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<TracesFromPriorRequest> CreateTracesFromPriorRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t num_traces = 0) {
  TracesFromPriorRequestBuilder builder_(_fbb);
  builder_.add_num_traces(num_traces);
  return builder_.Finish();
}

struct TracesFromPriorReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TRACES = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<Trace>> *traces() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Trace>> *>(VT_TRACES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_TRACES) &&
           verifier.Verify(traces()) &&
           verifier.VerifyVectorOfTables(traces()) &&
           verifier.EndTable();
  }
};

struct TracesFromPriorReplyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_traces(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Trace>>> traces) {
    fbb_.AddOffset(TracesFromPriorReply::VT_TRACES, traces);
  }
  TracesFromPriorReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TracesFromPriorReplyBuilder &operator=(const TracesFromPriorReplyBuilder &);
  flatbuffers::Offset<TracesFromPriorReply> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<TracesFromPriorReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<TracesFromPriorReply> CreateTracesFromPriorReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Trace>>> traces = 0) {
  TracesFromPriorReplyBuilder builder_(_fbb);
  builder_.add_traces(traces);
  return builder_.Finish();
}

inline flatbuffers::Offset<TracesFromPriorReply> CreateTracesFromPriorReplyDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<Trace>> *traces = nullptr) {
  return infcomp::CreateTracesFromPriorReply(
      _fbb,
      traces ? _fbb.CreateVector<flatbuffers::Offset<Trace>>(*traces) : 0);
}

struct ObservesInitRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_OBSERVES = 4
  };
  const NDArray *observes() const {
    return GetPointer<const NDArray *>(VT_OBSERVES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBSERVES) &&
           verifier.VerifyTable(observes()) &&
           verifier.EndTable();
  }
};

struct ObservesInitRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_observes(flatbuffers::Offset<NDArray> observes) {
    fbb_.AddOffset(ObservesInitRequest::VT_OBSERVES, observes);
  }
  ObservesInitRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ObservesInitRequestBuilder &operator=(const ObservesInitRequestBuilder &);
  flatbuffers::Offset<ObservesInitRequest> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<ObservesInitRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<ObservesInitRequest> CreateObservesInitRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<NDArray> observes = 0) {
  ObservesInitRequestBuilder builder_(_fbb);
  builder_.add_observes(observes);
  return builder_.Finish();
}

struct ObservesInitReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SUCCESS = 4
  };
  bool success() const {
    return GetField<uint8_t>(VT_SUCCESS, 0) != 0;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_SUCCESS) &&
           verifier.EndTable();
  }
};

struct ObservesInitReplyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_success(bool success) {
    fbb_.AddElement<uint8_t>(ObservesInitReply::VT_SUCCESS, static_cast<uint8_t>(success), 0);
  }
  ObservesInitReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ObservesInitReplyBuilder &operator=(const ObservesInitReplyBuilder &);
  flatbuffers::Offset<ObservesInitReply> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<ObservesInitReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<ObservesInitReply> CreateObservesInitReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool success = false) {
  ObservesInitReplyBuilder builder_(_fbb);
  builder_.add_success(success);
  return builder_.Finish();
}

struct ProposalRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CURRENT_SAMPLE = 4,
    VT_PREVIOUS_SAMPLE = 6
  };
  const Sample *current_sample() const {
    return GetPointer<const Sample *>(VT_CURRENT_SAMPLE);
  }
  const Sample *previous_sample() const {
    return GetPointer<const Sample *>(VT_PREVIOUS_SAMPLE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_CURRENT_SAMPLE) &&
           verifier.VerifyTable(current_sample()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PREVIOUS_SAMPLE) &&
           verifier.VerifyTable(previous_sample()) &&
           verifier.EndTable();
  }
};

struct ProposalRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_current_sample(flatbuffers::Offset<Sample> current_sample) {
    fbb_.AddOffset(ProposalRequest::VT_CURRENT_SAMPLE, current_sample);
  }
  void add_previous_sample(flatbuffers::Offset<Sample> previous_sample) {
    fbb_.AddOffset(ProposalRequest::VT_PREVIOUS_SAMPLE, previous_sample);
  }
  ProposalRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ProposalRequestBuilder &operator=(const ProposalRequestBuilder &);
  flatbuffers::Offset<ProposalRequest> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<ProposalRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<ProposalRequest> CreateProposalRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Sample> current_sample = 0,
    flatbuffers::Offset<Sample> previous_sample = 0) {
  ProposalRequestBuilder builder_(_fbb);
  builder_.add_previous_sample(previous_sample);
  builder_.add_current_sample(current_sample);
  return builder_.Finish();
}

struct ProposalReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SUCCESS = 4,
    VT_DISTRIBUTION_TYPE = 6,
    VT_DISTRIBUTION = 8
  };
  bool success() const {
    return GetField<uint8_t>(VT_SUCCESS, 0) != 0;
  }
  Distribution distribution_type() const {
    return static_cast<Distribution>(GetField<uint8_t>(VT_DISTRIBUTION_TYPE, 0));
  }
  const void *distribution() const {
    return GetPointer<const void *>(VT_DISTRIBUTION);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_SUCCESS) &&
           VerifyField<uint8_t>(verifier, VT_DISTRIBUTION_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_DISTRIBUTION) &&
           VerifyDistribution(verifier, distribution(), distribution_type()) &&
           verifier.EndTable();
  }
};

struct ProposalReplyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_success(bool success) {
    fbb_.AddElement<uint8_t>(ProposalReply::VT_SUCCESS, static_cast<uint8_t>(success), 0);
  }
  void add_distribution_type(Distribution distribution_type) {
    fbb_.AddElement<uint8_t>(ProposalReply::VT_DISTRIBUTION_TYPE, static_cast<uint8_t>(distribution_type), 0);
  }
  void add_distribution(flatbuffers::Offset<void> distribution) {
    fbb_.AddOffset(ProposalReply::VT_DISTRIBUTION, distribution);
  }
  ProposalReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ProposalReplyBuilder &operator=(const ProposalReplyBuilder &);
  flatbuffers::Offset<ProposalReply> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<ProposalReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<ProposalReply> CreateProposalReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool success = false,
    Distribution distribution_type = Distribution::NONE,
    flatbuffers::Offset<void> distribution = 0) {
  ProposalReplyBuilder builder_(_fbb);
  builder_.add_distribution(distribution);
  builder_.add_distribution_type(distribution_type);
  builder_.add_success(success);
  return builder_.Finish();
}

inline bool VerifyMessageBody(flatbuffers::Verifier &verifier, const void *obj, MessageBody type) {
  switch (type) {
    case MessageBody::NONE: {
      return true;
    }
    case MessageBody::TracesFromPriorRequest: {
      auto ptr = reinterpret_cast<const TracesFromPriorRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody::ObservesInitRequest: {
      auto ptr = reinterpret_cast<const ObservesInitRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody::ProposalRequest: {
      auto ptr = reinterpret_cast<const ProposalRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody::TracesFromPriorReply: {
      auto ptr = reinterpret_cast<const TracesFromPriorReply *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody::ObservesInitReply: {
      auto ptr = reinterpret_cast<const ObservesInitReply *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody::ProposalReply: {
      auto ptr = reinterpret_cast<const ProposalReply *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyMessageBodyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyMessageBody(
        verifier,  values->Get(i), types->GetEnum<MessageBody>(i))) {
      return false;
    }
  }
  return true;
}

inline bool VerifyDistribution(flatbuffers::Verifier &verifier, const void *obj, Distribution type) {
  switch (type) {
    case Distribution::NONE: {
      return true;
    }
    case Distribution::Categorical: {
      auto ptr = reinterpret_cast<const Categorical *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Distribution::Discrete: {
      auto ptr = reinterpret_cast<const Discrete *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Distribution::Flip: {
      auto ptr = reinterpret_cast<const Flip *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Distribution::Normal: {
      auto ptr = reinterpret_cast<const Normal *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Distribution::UniformDiscrete: {
      auto ptr = reinterpret_cast<const UniformDiscrete *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Distribution::VMF: {
      auto ptr = reinterpret_cast<const VMF *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyDistributionVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyDistribution(
        verifier,  values->Get(i), types->GetEnum<Distribution>(i))) {
      return false;
    }
  }
  return true;
}

inline const infcomp::Message *GetMessage(const void *buf) {
  return flatbuffers::GetRoot<infcomp::Message>(buf);
}

inline bool VerifyMessageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<infcomp::Message>(nullptr);
}

inline void FinishMessageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<infcomp::Message> root) {
  fbb.Finish(root);
}

}  // namespace infcomp

#endif  // FLATBUFFERS_GENERATED_INFCOMP_INFCOMP_H_