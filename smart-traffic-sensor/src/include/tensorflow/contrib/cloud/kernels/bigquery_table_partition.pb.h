// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/contrib/cloud/kernels/bigquery_table_partition.proto

#ifndef PROTOBUF_INCLUDED_tensorflow_2fcontrib_2fcloud_2fkernels_2fbigquery_5ftable_5fpartition_2eproto
#define PROTOBUF_INCLUDED_tensorflow_2fcontrib_2fcloud_2fkernels_2fbigquery_5ftable_5fpartition_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_tensorflow_2fcontrib_2fcloud_2fkernels_2fbigquery_5ftable_5fpartition_2eproto 

namespace protobuf_tensorflow_2fcontrib_2fcloud_2fkernels_2fbigquery_5ftable_5fpartition_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_tensorflow_2fcontrib_2fcloud_2fkernels_2fbigquery_5ftable_5fpartition_2eproto
namespace tensorflow {
class BigQueryTablePartition;
class BigQueryTablePartitionDefaultTypeInternal;
extern BigQueryTablePartitionDefaultTypeInternal _BigQueryTablePartition_default_instance_;
}  // namespace tensorflow
namespace google {
namespace protobuf {
template<> ::tensorflow::BigQueryTablePartition* Arena::CreateMaybeMessage<::tensorflow::BigQueryTablePartition>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace tensorflow {

// ===================================================================

class BigQueryTablePartition : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.BigQueryTablePartition) */ {
 public:
  BigQueryTablePartition();
  virtual ~BigQueryTablePartition();

  BigQueryTablePartition(const BigQueryTablePartition& from);

  inline BigQueryTablePartition& operator=(const BigQueryTablePartition& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BigQueryTablePartition(BigQueryTablePartition&& from) noexcept
    : BigQueryTablePartition() {
    *this = ::std::move(from);
  }

  inline BigQueryTablePartition& operator=(BigQueryTablePartition&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const BigQueryTablePartition& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BigQueryTablePartition* internal_default_instance() {
    return reinterpret_cast<const BigQueryTablePartition*>(
               &_BigQueryTablePartition_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(BigQueryTablePartition* other);
  friend void swap(BigQueryTablePartition& a, BigQueryTablePartition& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BigQueryTablePartition* New() const final {
    return CreateMaybeMessage<BigQueryTablePartition>(NULL);
  }

  BigQueryTablePartition* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<BigQueryTablePartition>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const BigQueryTablePartition& from);
  void MergeFrom(const BigQueryTablePartition& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BigQueryTablePartition* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int64 start_index = 1;
  void clear_start_index();
  static const int kStartIndexFieldNumber = 1;
  ::google::protobuf::int64 start_index() const;
  void set_start_index(::google::protobuf::int64 value);

  // int64 end_index = 2;
  void clear_end_index();
  static const int kEndIndexFieldNumber = 2;
  ::google::protobuf::int64 end_index() const;
  void set_end_index(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:tensorflow.BigQueryTablePartition)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int64 start_index_;
  ::google::protobuf::int64 end_index_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_tensorflow_2fcontrib_2fcloud_2fkernels_2fbigquery_5ftable_5fpartition_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BigQueryTablePartition

// int64 start_index = 1;
inline void BigQueryTablePartition::clear_start_index() {
  start_index_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 BigQueryTablePartition::start_index() const {
  // @@protoc_insertion_point(field_get:tensorflow.BigQueryTablePartition.start_index)
  return start_index_;
}
inline void BigQueryTablePartition::set_start_index(::google::protobuf::int64 value) {
  
  start_index_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.BigQueryTablePartition.start_index)
}

// int64 end_index = 2;
inline void BigQueryTablePartition::clear_end_index() {
  end_index_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 BigQueryTablePartition::end_index() const {
  // @@protoc_insertion_point(field_get:tensorflow.BigQueryTablePartition.end_index)
  return end_index_;
}
inline void BigQueryTablePartition::set_end_index(::google::protobuf::int64 value) {
  
  end_index_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.BigQueryTablePartition.end_index)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_tensorflow_2fcontrib_2fcloud_2fkernels_2fbigquery_5ftable_5fpartition_2eproto
