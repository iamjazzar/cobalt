// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: crx3.proto

#ifndef PROTOBUF_crx3_2eproto__INCLUDED
#define PROTOBUF_crx3_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
// @@protoc_insertion_point(includes)

namespace crx_file {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_crx3_2eproto();
void protobuf_AssignDesc_crx3_2eproto();
void protobuf_ShutdownFile_crx3_2eproto();

class AsymmetricKeyProof;
class CrxFileHeader;
class SignedData;

// ===================================================================

class CrxFileHeader : public ::google::protobuf::MessageLite {
 public:
  CrxFileHeader();
  virtual ~CrxFileHeader();

  CrxFileHeader(const CrxFileHeader& from);

  inline CrxFileHeader& operator=(const CrxFileHeader& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_.GetNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  inline ::std::string* mutable_unknown_fields() {
    return _unknown_fields_.MutableNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  static const CrxFileHeader& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const CrxFileHeader* internal_default_instance() {
    return default_instance_;
  }
#endif

  GOOGLE_ATTRIBUTE_NOINLINE void Swap(CrxFileHeader* other);

  // implements Message ----------------------------------------------

  inline CrxFileHeader* New() const { return New(NULL); }

  CrxFileHeader* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const CrxFileHeader& from);
  void MergeFrom(const CrxFileHeader& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }

 private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(CrxFileHeader* other);

 private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }

 public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .crx_file.AsymmetricKeyProof sha256_with_rsa = 2;
  int sha256_with_rsa_size() const;
  void clear_sha256_with_rsa();
  static const int kSha256WithRsaFieldNumber = 2;
  const ::crx_file::AsymmetricKeyProof& sha256_with_rsa(int index) const;
  ::crx_file::AsymmetricKeyProof* mutable_sha256_with_rsa(int index);
  ::crx_file::AsymmetricKeyProof* add_sha256_with_rsa();
  ::google::protobuf::RepeatedPtrField< ::crx_file::AsymmetricKeyProof>*
  mutable_sha256_with_rsa();
  const ::google::protobuf::RepeatedPtrField< ::crx_file::AsymmetricKeyProof>&
  sha256_with_rsa() const;

  // repeated .crx_file.AsymmetricKeyProof sha256_with_ecdsa = 3;
  int sha256_with_ecdsa_size() const;
  void clear_sha256_with_ecdsa();
  static const int kSha256WithEcdsaFieldNumber = 3;
  const ::crx_file::AsymmetricKeyProof& sha256_with_ecdsa(int index) const;
  ::crx_file::AsymmetricKeyProof* mutable_sha256_with_ecdsa(int index);
  ::crx_file::AsymmetricKeyProof* add_sha256_with_ecdsa();
  ::google::protobuf::RepeatedPtrField< ::crx_file::AsymmetricKeyProof>*
  mutable_sha256_with_ecdsa();
  const ::google::protobuf::RepeatedPtrField< ::crx_file::AsymmetricKeyProof>&
  sha256_with_ecdsa() const;

  // optional bytes signed_header_data = 10000;
  bool has_signed_header_data() const;
  void clear_signed_header_data();
  static const int kSignedHeaderDataFieldNumber = 10000;
  const ::std::string& signed_header_data() const;
  void set_signed_header_data(const ::std::string& value);
  void set_signed_header_data(const char* value);
  void set_signed_header_data(const void* value, size_t size);
  ::std::string* mutable_signed_header_data();
  ::std::string* release_signed_header_data();
  void set_allocated_signed_header_data(::std::string* signed_header_data);

  // @@protoc_insertion_point(class_scope:crx_file.CrxFileHeader)
 private:
  inline void set_has_signed_header_data();
  inline void clear_has_signed_header_data();

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::crx_file::AsymmetricKeyProof>
      sha256_with_rsa_;
  ::google::protobuf::RepeatedPtrField< ::crx_file::AsymmetricKeyProof>
      sha256_with_ecdsa_;
  ::google::protobuf::internal::ArenaStringPtr signed_header_data_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void protobuf_AddDesc_crx3_2eproto_impl();
#else
  friend void protobuf_AddDesc_crx3_2eproto();
#endif
  friend void protobuf_AssignDesc_crx3_2eproto();
  friend void protobuf_ShutdownFile_crx3_2eproto();

  void InitAsDefaultInstance();
  static CrxFileHeader* default_instance_;
};
// -------------------------------------------------------------------

class AsymmetricKeyProof : public ::google::protobuf::MessageLite {
 public:
  AsymmetricKeyProof();
  virtual ~AsymmetricKeyProof();

  AsymmetricKeyProof(const AsymmetricKeyProof& from);

  inline AsymmetricKeyProof& operator=(const AsymmetricKeyProof& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_.GetNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  inline ::std::string* mutable_unknown_fields() {
    return _unknown_fields_.MutableNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  static const AsymmetricKeyProof& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const AsymmetricKeyProof* internal_default_instance() {
    return default_instance_;
  }
#endif

  GOOGLE_ATTRIBUTE_NOINLINE void Swap(AsymmetricKeyProof* other);

  // implements Message ----------------------------------------------

  inline AsymmetricKeyProof* New() const { return New(NULL); }

  AsymmetricKeyProof* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const AsymmetricKeyProof& from);
  void MergeFrom(const AsymmetricKeyProof& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }

 private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(AsymmetricKeyProof* other);

 private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }

 public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes public_key = 1;
  bool has_public_key() const;
  void clear_public_key();
  static const int kPublicKeyFieldNumber = 1;
  const ::std::string& public_key() const;
  void set_public_key(const ::std::string& value);
  void set_public_key(const char* value);
  void set_public_key(const void* value, size_t size);
  ::std::string* mutable_public_key();
  ::std::string* release_public_key();
  void set_allocated_public_key(::std::string* public_key);

  // optional bytes signature = 2;
  bool has_signature() const;
  void clear_signature();
  static const int kSignatureFieldNumber = 2;
  const ::std::string& signature() const;
  void set_signature(const ::std::string& value);
  void set_signature(const char* value);
  void set_signature(const void* value, size_t size);
  ::std::string* mutable_signature();
  ::std::string* release_signature();
  void set_allocated_signature(::std::string* signature);

  // @@protoc_insertion_point(class_scope:crx_file.AsymmetricKeyProof)
 private:
  inline void set_has_public_key();
  inline void clear_has_public_key();
  inline void set_has_signature();
  inline void clear_has_signature();

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr public_key_;
  ::google::protobuf::internal::ArenaStringPtr signature_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void protobuf_AddDesc_crx3_2eproto_impl();
#else
  friend void protobuf_AddDesc_crx3_2eproto();
#endif
  friend void protobuf_AssignDesc_crx3_2eproto();
  friend void protobuf_ShutdownFile_crx3_2eproto();

  void InitAsDefaultInstance();
  static AsymmetricKeyProof* default_instance_;
};
// -------------------------------------------------------------------

class SignedData : public ::google::protobuf::MessageLite {
 public:
  SignedData();
  virtual ~SignedData();

  SignedData(const SignedData& from);

  inline SignedData& operator=(const SignedData& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_.GetNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  inline ::std::string* mutable_unknown_fields() {
    return _unknown_fields_.MutableNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  static const SignedData& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const SignedData* internal_default_instance() {
    return default_instance_;
  }
#endif

  GOOGLE_ATTRIBUTE_NOINLINE void Swap(SignedData* other);

  // implements Message ----------------------------------------------

  inline SignedData* New() const { return New(NULL); }

  SignedData* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const SignedData& from);
  void MergeFrom(const SignedData& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }

 private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SignedData* other);

 private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }

 public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes crx_id = 1;
  bool has_crx_id() const;
  void clear_crx_id();
  static const int kCrxIdFieldNumber = 1;
  const ::std::string& crx_id() const;
  void set_crx_id(const ::std::string& value);
  void set_crx_id(const char* value);
  void set_crx_id(const void* value, size_t size);
  ::std::string* mutable_crx_id();
  ::std::string* release_crx_id();
  void set_allocated_crx_id(::std::string* crx_id);

  // @@protoc_insertion_point(class_scope:crx_file.SignedData)
 private:
  inline void set_has_crx_id();
  inline void clear_has_crx_id();

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr crx_id_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void protobuf_AddDesc_crx3_2eproto_impl();
#else
  friend void protobuf_AddDesc_crx3_2eproto();
#endif
  friend void protobuf_AssignDesc_crx3_2eproto();
  friend void protobuf_ShutdownFile_crx3_2eproto();

  void InitAsDefaultInstance();
  static SignedData* default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// CrxFileHeader

// repeated .crx_file.AsymmetricKeyProof sha256_with_rsa = 2;
inline int CrxFileHeader::sha256_with_rsa_size() const {
  return sha256_with_rsa_.size();
}
inline void CrxFileHeader::clear_sha256_with_rsa() {
  sha256_with_rsa_.Clear();
}
inline const ::crx_file::AsymmetricKeyProof& CrxFileHeader::sha256_with_rsa(
    int index) const {
  // @@protoc_insertion_point(field_get:crx_file.CrxFileHeader.sha256_with_rsa)
  return sha256_with_rsa_.Get(index);
}
inline ::crx_file::AsymmetricKeyProof* CrxFileHeader::mutable_sha256_with_rsa(
    int index) {
  // @@protoc_insertion_point(field_mutable:crx_file.CrxFileHeader.sha256_with_rsa)
  return sha256_with_rsa_.Mutable(index);
}
inline ::crx_file::AsymmetricKeyProof* CrxFileHeader::add_sha256_with_rsa() {
  // @@protoc_insertion_point(field_add:crx_file.CrxFileHeader.sha256_with_rsa)
  return sha256_with_rsa_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::crx_file::AsymmetricKeyProof>*
CrxFileHeader::mutable_sha256_with_rsa() {
  // @@protoc_insertion_point(field_mutable_list:crx_file.CrxFileHeader.sha256_with_rsa)
  return &sha256_with_rsa_;
}
inline const ::google::protobuf::RepeatedPtrField<
    ::crx_file::AsymmetricKeyProof>&
CrxFileHeader::sha256_with_rsa() const {
  // @@protoc_insertion_point(field_list:crx_file.CrxFileHeader.sha256_with_rsa)
  return sha256_with_rsa_;
}

// repeated .crx_file.AsymmetricKeyProof sha256_with_ecdsa = 3;
inline int CrxFileHeader::sha256_with_ecdsa_size() const {
  return sha256_with_ecdsa_.size();
}
inline void CrxFileHeader::clear_sha256_with_ecdsa() {
  sha256_with_ecdsa_.Clear();
}
inline const ::crx_file::AsymmetricKeyProof& CrxFileHeader::sha256_with_ecdsa(
    int index) const {
  // @@protoc_insertion_point(field_get:crx_file.CrxFileHeader.sha256_with_ecdsa)
  return sha256_with_ecdsa_.Get(index);
}
inline ::crx_file::AsymmetricKeyProof* CrxFileHeader::mutable_sha256_with_ecdsa(
    int index) {
  // @@protoc_insertion_point(field_mutable:crx_file.CrxFileHeader.sha256_with_ecdsa)
  return sha256_with_ecdsa_.Mutable(index);
}
inline ::crx_file::AsymmetricKeyProof* CrxFileHeader::add_sha256_with_ecdsa() {
  // @@protoc_insertion_point(field_add:crx_file.CrxFileHeader.sha256_with_ecdsa)
  return sha256_with_ecdsa_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::crx_file::AsymmetricKeyProof>*
CrxFileHeader::mutable_sha256_with_ecdsa() {
  // @@protoc_insertion_point(field_mutable_list:crx_file.CrxFileHeader.sha256_with_ecdsa)
  return &sha256_with_ecdsa_;
}
inline const ::google::protobuf::RepeatedPtrField<
    ::crx_file::AsymmetricKeyProof>&
CrxFileHeader::sha256_with_ecdsa() const {
  // @@protoc_insertion_point(field_list:crx_file.CrxFileHeader.sha256_with_ecdsa)
  return sha256_with_ecdsa_;
}

// optional bytes signed_header_data = 10000;
inline bool CrxFileHeader::has_signed_header_data() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CrxFileHeader::set_has_signed_header_data() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CrxFileHeader::clear_has_signed_header_data() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CrxFileHeader::clear_signed_header_data() {
  signed_header_data_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_signed_header_data();
}
inline const ::std::string& CrxFileHeader::signed_header_data() const {
  // @@protoc_insertion_point(field_get:crx_file.CrxFileHeader.signed_header_data)
  return signed_header_data_.GetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CrxFileHeader::set_signed_header_data(const ::std::string& value) {
  set_has_signed_header_data();
  signed_header_data_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:crx_file.CrxFileHeader.signed_header_data)
}
inline void CrxFileHeader::set_signed_header_data(const char* value) {
  set_has_signed_header_data();
  signed_header_data_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value));
  // @@protoc_insertion_point(field_set_char:crx_file.CrxFileHeader.signed_header_data)
}
inline void CrxFileHeader::set_signed_header_data(const void* value,
                                                  size_t size) {
  set_has_signed_header_data();
  signed_header_data_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:crx_file.CrxFileHeader.signed_header_data)
}
inline ::std::string* CrxFileHeader::mutable_signed_header_data() {
  set_has_signed_header_data();
  // @@protoc_insertion_point(field_mutable:crx_file.CrxFileHeader.signed_header_data)
  return signed_header_data_.MutableNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CrxFileHeader::release_signed_header_data() {
  // @@protoc_insertion_point(field_release:crx_file.CrxFileHeader.signed_header_data)
  clear_has_signed_header_data();
  return signed_header_data_.ReleaseNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CrxFileHeader::set_allocated_signed_header_data(
    ::std::string* signed_header_data) {
  if (signed_header_data != NULL) {
    set_has_signed_header_data();
  } else {
    clear_has_signed_header_data();
  }
  signed_header_data_.SetAllocatedNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      signed_header_data);
  // @@protoc_insertion_point(field_set_allocated:crx_file.CrxFileHeader.signed_header_data)
}

// -------------------------------------------------------------------

// AsymmetricKeyProof

// optional bytes public_key = 1;
inline bool AsymmetricKeyProof::has_public_key() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AsymmetricKeyProof::set_has_public_key() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AsymmetricKeyProof::clear_has_public_key() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AsymmetricKeyProof::clear_public_key() {
  public_key_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_public_key();
}
inline const ::std::string& AsymmetricKeyProof::public_key() const {
  // @@protoc_insertion_point(field_get:crx_file.AsymmetricKeyProof.public_key)
  return public_key_.GetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AsymmetricKeyProof::set_public_key(const ::std::string& value) {
  set_has_public_key();
  public_key_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:crx_file.AsymmetricKeyProof.public_key)
}
inline void AsymmetricKeyProof::set_public_key(const char* value) {
  set_has_public_key();
  public_key_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value));
  // @@protoc_insertion_point(field_set_char:crx_file.AsymmetricKeyProof.public_key)
}
inline void AsymmetricKeyProof::set_public_key(const void* value, size_t size) {
  set_has_public_key();
  public_key_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:crx_file.AsymmetricKeyProof.public_key)
}
inline ::std::string* AsymmetricKeyProof::mutable_public_key() {
  set_has_public_key();
  // @@protoc_insertion_point(field_mutable:crx_file.AsymmetricKeyProof.public_key)
  return public_key_.MutableNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AsymmetricKeyProof::release_public_key() {
  // @@protoc_insertion_point(field_release:crx_file.AsymmetricKeyProof.public_key)
  clear_has_public_key();
  return public_key_.ReleaseNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AsymmetricKeyProof::set_allocated_public_key(
    ::std::string* public_key) {
  if (public_key != NULL) {
    set_has_public_key();
  } else {
    clear_has_public_key();
  }
  public_key_.SetAllocatedNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), public_key);
  // @@protoc_insertion_point(field_set_allocated:crx_file.AsymmetricKeyProof.public_key)
}

// optional bytes signature = 2;
inline bool AsymmetricKeyProof::has_signature() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void AsymmetricKeyProof::set_has_signature() {
  _has_bits_[0] |= 0x00000002u;
}
inline void AsymmetricKeyProof::clear_has_signature() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void AsymmetricKeyProof::clear_signature() {
  signature_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_signature();
}
inline const ::std::string& AsymmetricKeyProof::signature() const {
  // @@protoc_insertion_point(field_get:crx_file.AsymmetricKeyProof.signature)
  return signature_.GetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AsymmetricKeyProof::set_signature(const ::std::string& value) {
  set_has_signature();
  signature_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:crx_file.AsymmetricKeyProof.signature)
}
inline void AsymmetricKeyProof::set_signature(const char* value) {
  set_has_signature();
  signature_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value));
  // @@protoc_insertion_point(field_set_char:crx_file.AsymmetricKeyProof.signature)
}
inline void AsymmetricKeyProof::set_signature(const void* value, size_t size) {
  set_has_signature();
  signature_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:crx_file.AsymmetricKeyProof.signature)
}
inline ::std::string* AsymmetricKeyProof::mutable_signature() {
  set_has_signature();
  // @@protoc_insertion_point(field_mutable:crx_file.AsymmetricKeyProof.signature)
  return signature_.MutableNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AsymmetricKeyProof::release_signature() {
  // @@protoc_insertion_point(field_release:crx_file.AsymmetricKeyProof.signature)
  clear_has_signature();
  return signature_.ReleaseNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AsymmetricKeyProof::set_allocated_signature(
    ::std::string* signature) {
  if (signature != NULL) {
    set_has_signature();
  } else {
    clear_has_signature();
  }
  signature_.SetAllocatedNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), signature);
  // @@protoc_insertion_point(field_set_allocated:crx_file.AsymmetricKeyProof.signature)
}

// -------------------------------------------------------------------

// SignedData

// optional bytes crx_id = 1;
inline bool SignedData::has_crx_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SignedData::set_has_crx_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SignedData::clear_has_crx_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SignedData::clear_crx_id() {
  crx_id_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_crx_id();
}
inline const ::std::string& SignedData::crx_id() const {
  // @@protoc_insertion_point(field_get:crx_file.SignedData.crx_id)
  return crx_id_.GetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SignedData::set_crx_id(const ::std::string& value) {
  set_has_crx_id();
  crx_id_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:crx_file.SignedData.crx_id)
}
inline void SignedData::set_crx_id(const char* value) {
  set_has_crx_id();
  crx_id_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value));
  // @@protoc_insertion_point(field_set_char:crx_file.SignedData.crx_id)
}
inline void SignedData::set_crx_id(const void* value, size_t size) {
  set_has_crx_id();
  crx_id_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:crx_file.SignedData.crx_id)
}
inline ::std::string* SignedData::mutable_crx_id() {
  set_has_crx_id();
  // @@protoc_insertion_point(field_mutable:crx_file.SignedData.crx_id)
  return crx_id_.MutableNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SignedData::release_crx_id() {
  // @@protoc_insertion_point(field_release:crx_file.SignedData.crx_id)
  clear_has_crx_id();
  return crx_id_.ReleaseNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SignedData::set_allocated_crx_id(::std::string* crx_id) {
  if (crx_id != NULL) {
    set_has_crx_id();
  } else {
    clear_has_crx_id();
  }
  crx_id_.SetAllocatedNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), crx_id);
  // @@protoc_insertion_point(field_set_allocated:crx_file.SignedData.crx_id)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// @@protoc_insertion_point(namespace_scope)

}  // namespace crx_file

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_crx3_2eproto__INCLUDED