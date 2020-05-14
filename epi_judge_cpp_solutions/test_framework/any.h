
#pragma once

#include <memory>
#include <typeindex>
#include <utility>

#include "fmt_print.h"
#include "serialization_traits.h"
#include "test_utils_meta.h"

namespace test_framework {

namespace any {
class AnyBase {
 public:
  virtual ~AnyBase() = default;

  virtual std::type_index Typeid() const = 0;

  virtual std::string TypeName() const = 0;

  virtual void Print(std::ostream&) const = 0;

  template <typename T>
  const T* TryCast() const {
    if (std::type_index(typeid(T)) == Typeid()) {
      return reinterpret_cast<const T*>(MemberPtr());
    } else {
      return nullptr;
    }
  }

  template <typename T>
  const T& Cast() const {
    const T* ptr = TryCast<T>();
    if (!ptr) {
      throw std::runtime_error(FmtStr("Any: expected type {}, got {}",
                                      TypeName(), typeid(T).name()));
    }
    return *ptr;
  }

  virtual void* MemberPtr() = 0;

  virtual const void* MemberPtr() const = 0;
};

template <typename T>
class AnySpecialization : public AnyBase {
 public:
  template <typename FwdT>
  explicit AnySpecialization(FwdT&& value)
      : value_(std::forward<FwdT>(value)) {}

  std::type_index Typeid() const override {
    return std::type_index(typeid(T));
  }

  std::string TypeName() const override { return typeid(T).name(); }

  void Print(std::ostream& out) const override { PrintTo(out, value_); }

  void* MemberPtr() override { return &value_; }

  const void* MemberPtr() const override { return &value_; }

 private:
  T value_;
};
}  // namespace any

class Any {
  std::shared_ptr<any::AnyBase> ptr_;

  template <typename T>
  using AnySpecialization = any::AnySpecialization<remove_ref_cv_t<T>>;

 public:
  template <typename FwdT>
  Any(FwdT&& value)
      : ptr_(std::static_pointer_cast<any::AnyBase>(
            std::make_shared<AnySpecialization<FwdT>>(
                std::forward<FwdT>(value)))) {}

  template <typename T>
  const T* TryCast() const {
    return ptr_->TryCast<T>();
  }

  template <typename T>
  const T& Cast() const {
    return ptr_->Cast<T>();
  }

  friend std::ostream& operator<<(std::ostream& out, const Any& any) {
    any.ptr_->Print(out);
    return out;
  }
};
}  // namespace test_framework
