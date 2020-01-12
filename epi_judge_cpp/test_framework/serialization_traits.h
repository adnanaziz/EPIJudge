
#pragma once

#include <deque>
#include <iterator>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

#include "binary_tree_utils.h"
#include "json.h"
#include "test_utils_meta.h"

namespace test_framework {

using json = nlohmann::json;

struct NoSpecializationTag {};

/**
 * SerializationTrait defines a mapping between possible types from a
 * function signature and the ones from test data file. It also adds a
 * primitive type reflexion.
 *
 * For adding a new type one should create a template specialization for
 * SerializationTrait structure and implement Name(), Parse(),
 * GetMetricNames(), GetMetrics(), and Equal() static methods and
 * serialization_type typedef.
 *
 * Test data file types: string, integers, floats, multi-level containers
 * (vector, deque, set, unordered set), tuple
 *
 * Conversion rules:
 *  - unsigned -> signed
 *  - char and short -> int
 *  - const and reference modifiers are dropped
 */
template <typename T, typename SFINAE = void>
struct SerializationTrait : NoSpecializationTag {
  using serialization_type = T;

  static constexpr const char* Name() { return typeid(T).name(); }

  static void Parse(const json& json_object) {
    static_assert(sizeof(T) < 0, "Unsupported type");
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    static_assert(sizeof(T) < 0, "Unsupported type");
    return {};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    static_assert(sizeof(T) < 0, "Unsupported type");
    return {};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    static_assert(HasEqualOp<serialization_type>::value,
                  "Missing == operator for the type");
    return a == b;
  }
};

template <typename T>
using HasSerializationTraitSpecialization = std::integral_constant<
    bool,
    !std::is_base_of<NoSpecializationTag, SerializationTrait<T>>::value>;

/**
 * void specialization.
 * It is used when tested function has void return type.
 */
template <>
struct SerializationTrait<void, void> {
  using serialization_type = void;

  static constexpr const char* Name() { return "void"; }

  static void Parse(const json& json_object) {
    throw std::runtime_error("Can't parse void");
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    throw std::runtime_error("Can't process void");
  }

  static std::vector<int> GetMetrics(int x) {
    throw std::runtime_error("Can't process void");
  }
};

/**
 * VoidPlaceholder specialization.
 * It is used when tested function has void return type.
 */
template <>
struct SerializationTrait<VoidPlaceholder, void>
    : SerializationTrait<void, void> {
  using serialization_type = VoidPlaceholder;
};

/**
 * Signed and unsigned 8-, 16-, and 32-bits integer specialization.
 */
template <typename T>
struct SerializationTrait<
    T, std::enable_if_t<std::is_integral<T>::value && sizeof(T) <= 4 &&
                        is_pure_type<T>::value>> {
  using serialization_type = int32_t;

  static constexpr const char* Name() { return "int"; }

  static T Parse(const json& json_object) {
    return static_cast<T>(json_object);
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(std::abs(x))};
  }

  static bool Equal(serialization_type a, serialization_type b) {
    return a == b;
  }
};

/**
 * Signed 64-bit integer specialization.
 */
template <typename T>
struct SerializationTrait<
    T, std::enable_if_t<std::is_integral<T>::value && sizeof(T) == 8 &&
                        std::is_signed<T>::value && is_pure_type<T>::value>> {
  using serialization_type = int64_t;

  static constexpr const char* Name() { return "long"; }

  static serialization_type Parse(const json& json_object) {
    return static_cast<serialization_type>(json_object);
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(std::min<serialization_type>(
        std::abs(x), std::numeric_limits<int>::max()))};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    return a == b;
  }
};

/**
 * Unsigned 64-bit integer specialization.
 */
template <typename T>
struct SerializationTrait<
    T,
    std::enable_if_t<std::is_integral<T>::value && sizeof(T) == 8 &&
                     !std::is_signed<T>::value && is_pure_type<T>::value>> {
  using serialization_type = uint64_t;

  static constexpr const char* Name() { return "long"; }

  static serialization_type Parse(const json& json_object) {
    return static_cast<serialization_type>(json_object);
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(
        std::min<serialization_type>(x, std::numeric_limits<int>::max()))};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    return a == b;
  }
};

/**
 * Float specialization.
 */
template <>
struct SerializationTrait<float, void> {
  using serialization_type = float;

  static constexpr const char* Name() { return "float"; }

  static serialization_type Parse(const json& json_object) {
    return static_cast<serialization_type>(json_object);
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(std::min<serialization_type>(
        std::abs(x), std::numeric_limits<int>::max()))};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    constexpr float eps = 1E-4f;
    constexpr float abs_eps = 1E-10f;
    return std::abs(a - b) <=
           std::max(eps * std::max(std::abs(a), std::abs(b)), abs_eps);
  }
};

/**
 * Double specialization.
 */
template <>
struct SerializationTrait<double, void> {
  using serialization_type = double;

  static constexpr const char* Name() { return "float"; }

  static serialization_type Parse(const json& json_object) {
    return static_cast<serialization_type>(json_object);
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(std::min<serialization_type>(
        std::abs(x), std::numeric_limits<int>::max()))};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    constexpr double eps = 1E-6;
    constexpr double abs_eps = 1E-20;
    return std::abs(a - b) <=
           std::max(eps * std::max(std::abs(a), std::abs(b)), abs_eps);
  }
};

/**
 * Boolean specialization.
 */
template <>
struct SerializationTrait<bool, void> {
  using serialization_type = bool;

  static constexpr const char* Name() { return "bool"; }

  static serialization_type Parse(const json& json_object) {
    return json_object;
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {};
  }

  static bool Equal(serialization_type a, serialization_type b) {
    return a == b;
  }
};

/**
 * std::string specialization.
 */
template <>
struct SerializationTrait<std::string, void> {
  using serialization_type = std::string;

  static constexpr const char* Name() { return "string"; }

  static serialization_type Parse(const json& json_object) {
    return json_object;
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {FmtStr("size({})", arg_name)};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(x.size())};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    return a == b;
  }
};

/**
 * std::vector specialization.
 */
template <typename Inner>
struct SerializationTrait<std::vector<Inner>, void> {
  using inner_type_trait = SerializationTrait<Inner>;
  using serialization_type =
      std::vector<typename inner_type_trait::serialization_type>;

  static const char* Name() {
    static std::string s = FmtStr("array({})", inner_type_trait::Name());
    return s.c_str();
  }

  static serialization_type Parse(const json& json_object) {
    serialization_type result;
    std::transform(
        json_object.begin(), json_object.end(), std::back_inserter(result),
        [](const auto& inner) { return inner_type_trait::Parse(inner); });
    return result;
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {FmtStr("size({})", arg_name)};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(x.size())};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    return std::equal(std::begin(a), std::end(a), std::begin(b), std::end(b),
                      inner_type_trait::Equal);
  }
};

/**
 * Helper class for container specializations.
 */
template <template <typename...> class Container, typename Inner>
struct ArrayBasedTypeSerTrait : SerializationTrait<std::vector<Inner>> {
  using serialization_type = Container<Inner>;

  static serialization_type Parse(const json& json_object) {
    auto v = SerializationTrait<std::vector<Inner>>::Parse(json_object);
    return FromVector(v);
  }

  static serialization_type FromVector(std::vector<Inner>& v) {
    return {std::begin(v), std::end(v)};
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {FmtStr("size({})", arg_name)};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(x.size())};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    return std::equal(std::begin(a), std::end(a), std::begin(b), std::end(b),
                      SerializationTrait<Inner>::Equal);
  }
};

/**
 * std::deque specialization.
 */
template <typename Inner>
struct SerializationTrait<std::deque<Inner>, void>
    : ArrayBasedTypeSerTrait<std::deque, Inner> {};

/**
 * std::set specialization.
 */
template <typename Inner>
struct SerializationTrait<std::set<Inner>, void>
    : ArrayBasedTypeSerTrait<std::set, Inner> {
  using inner_type_trait = SerializationTrait<Inner>;

  static const char* Name() {
    static std::string s = FmtStr("set({})", inner_type_trait::Name());
    return s.c_str();
  }
};

/**
 * std::unordered_set specialization.
 */
template <typename Inner>
struct SerializationTrait<std::unordered_set<Inner>, void>
    : ArrayBasedTypeSerTrait<std::unordered_set, Inner> {
  using inner_type_trait = SerializationTrait<Inner>;

  static const char* Name() {
    static std::string s = FmtStr("set({})", inner_type_trait::Name());
    return s.c_str();
  }
};

/**
 * std::tuple specialization
 */
template <typename... TupleTypes>
struct SerializationTrait<std::tuple<TupleTypes...>, void> {
  using tuple_type = std::tuple<TupleTypes...>;
  using serialization_type = std::tuple<
      typename SerializationTrait<TupleTypes>::serialization_type...>;

  template <size_t Begin, size_t End>
  using this_sub_tuple_t = sub_tuple_t<tuple_type, Begin, End>;

  using this_tuple_size = std::tuple_size<tuple_type>;
  using index_sequence = std::make_index_sequence<this_tuple_size::value>;

  template <size_t I>
  using ith_item_t = std::tuple_element_t<I, tuple_type>;

  template <size_t I>
  using ith_item_trait = SerializationTrait<ith_item_t<I>>;

  static const char* Name() {
    static std::string s = FmtStr("tuple({})", InnerTypesName());
    return s.c_str();
  }

  static serialization_type Parse(const json& json_object) {
    if (json_object.size() != this_tuple_size::value) {
      throw std::runtime_error(
          FmtStr("Tuple parser: invalid item count: expected {}, actual {}",
                 this_tuple_size::value, json_object.size()));
    }
    return JsonArrayToTuple(json_object, index_sequence());
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return GetMetricNamesImpl(arg_name, index_sequence());
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return GetMetricsImpl(x, index_sequence());
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    return EqualImpl(a, b, index_sequence());
  }

 private:
  static std::string InnerTypesName() {
    return Concatenate(",", SerializationTrait<TupleTypes>::Name()...);
  }

  template <size_t... I>
  static std::vector<std::string> GetMetricNamesImpl(
      const std::string& arg_name, std::index_sequence<I...> /*unused*/) {
    return FlattenVector<std::string>({ith_item_trait<I>::GetMetricNames(
        FmtStr("{}[{}]", arg_name, I))...});
  }

  template <size_t... I>
  static std::vector<int> GetMetricsImpl(
      const serialization_type& x, std::index_sequence<I...> /*unused*/) {
    return FlattenVector<int>(
        {ith_item_trait<I>::GetMetrics(std::get<I>(x))...});
  }

  template <size_t... I>
  static serialization_type JsonArrayToTuple(
      const json& json_arr, std::index_sequence<I...> /*unused*/) {
    return std::make_tuple(ith_item_trait<I>::Parse(json_arr[I])...);
  };

  template <size_t... I>
  static bool EqualImpl(const serialization_type& a,
                        const serialization_type& b,
                        std::index_sequence<I...> /*unused*/) {
    return FirstFalseArg(ith_item_trait<I>::Equal(std::get<I>(a),
                                                  std::get<I>(b))...) == 0;
  }
};

/**
 * Helper class for binary tree parser.
 */
template <bool HasParent>
struct BinaryTreeSerializationTraitHelper {
  template <typename Node, typename Parent>
  static void InitParent(const Node& n, const Parent& p) {}
};

template <>
struct BinaryTreeSerializationTraitHelper<true> {
  template <typename Node, typename Parent>
  static void InitParent(Node& n, Parent& p) {
    n->parent = p;
  }
};

/**
 * Common implementation for binary tree specializations.
 * @tparam SmartPtrT - binary tree smart pointer type
 *                  (usually smart_ptr or unique_ptr).
 * @tparam NodeT - binary tree node type.
 * @tparam KeyT - node key type.
 * @tparam HasParent - affects the parent pointer initialization.
 */
template <typename NodePtrT, bool HasParent>
struct BinaryTreeSerializationTrait {
  using serialization_type = NodePtrT;

  using node_t = template_param_by_index_t<NodePtrT, 0>;
  using key_t = template_param_by_index_t<node_t, 0>;
  using inner_type_trait = SerializationTrait<key_t>;

  static const char* Name() {
    static std::string s =
        FmtStr("binary_tree({})", inner_type_trait::Name());
    return s.c_str();
  }

  static serialization_type Parse(const json& json_object) {
    std::vector<node_t*> nodes;
    for (const auto& x : json_object) {
      nodes.emplace_back(
          x.is_null() ? nullptr : new node_t{inner_type_trait::Parse(x)});
    }
    std::vector<node_t*> candidate_children(std::rbegin(nodes),
                                            std::rend(nodes));
    auto root = serialization_type(candidate_children.back());
    candidate_children.pop_back();

    using trait_helper = BinaryTreeSerializationTraitHelper<HasParent>;

    for (const auto& node : nodes) {
      if (node) {
        if (!candidate_children.empty()) {
          node->left = serialization_type(candidate_children.back());
          if (node->left) {
            trait_helper::InitParent(node->left, node);
          }
          candidate_children.pop_back();
        } else {
          node->left = nullptr;
        }
        if (!candidate_children.empty()) {
          node->right = serialization_type(candidate_children.back());
          if (node->right) {
            trait_helper::InitParent(node->right, node);
          }
          candidate_children.pop_back();
        } else {
          node->right = nullptr;
        }
      }
    }
    return root;
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {FmtStr("size({})", arg_name), FmtStr("height({})", arg_name)};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {BinaryTreeSize(x), BinaryTreeHeight(x)};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    return EqualBinaryTrees(a, b);
  }
};

#define DECLARE_BINARY_TREE_TYPE(KeyType, NodePtrType, HasParent) \
  namespace test_framework {                                      \
  template <typename KeyType>                                     \
  struct SerializationTrait<NodePtrType>                          \
      : BinaryTreeSerializationTrait<NodePtrType, HasParent> {};  \
  namespace meta {                                                \
  template <typename KeyType>                                     \
  struct IsBinaryTreeImpl<NodePtrType> : std::true_type {};       \
  }                                                               \
  }

/**
 * A specialization for handling types with modifiers.
 * Since we use full template specializations,
 * a certain specialization won't be picked up by compiler
 * if the type has an additional modifier (reference, for example).
 *
 * So, having SerializationTrait<std::string> specialization,
 * it would be dropped if we try to instantiate
 * SerializationTrait<const std::string&>.
 *
 * This partial specialization solves the following problem
 * by instructing a compiler that serialization traits
 * for a type with modifiers are the same as
 * for the pure type (without modifiers).
 * For pure types this specialization
 * is disabled by enable_if.
 */
template <typename T>
struct SerializationTrait<T, std::enable_if_t<!is_pure_type<T>::value>>
    : SerializationTrait<remove_ref_cv_t<T>> {};

/**
 * Helper function for writing a serialization traits specialization
 * for simple user types (plain structures without pointers and
 * other non-trivial attributes). The user structure would be
 * encoded as a tuple in test data.
 *
 * Usage example:
 * struct Point {int x, y;};
 * template <>
 * struct SerializationTrait<Point>:
 *     UserSerTrait<Point, int, int> {};
 *
 * At first, data is parsed into std::tuple.
 * Then the target object is constructed from tuple
 * (@see UserSerTrait::FromTuple).
 * If the default implementation of UserSerTrait::FromTuple is not suitable,
 * one can provide their own implementation
 * in the SerializationTrait<UserType> specialization.
 * It will be picked up using CRTP technique.
 *
 * @tparam UserType - target user type.
 * @tparam Members - a list of argument types, from which
 * it must be possible to construct an instance of UserType
 * either by calling a constructor or using aggregate initialization.
 */
template <typename UserType, typename... Members>
struct UserSerTrait : SerializationTrait<std::tuple<Members...>> {
  using serialization_type = UserType;

  static serialization_type Parse(const json& json_object) {
    auto t = SerializationTrait<std::tuple<Members...>>::Parse(json_object);
    return SerializationTrait<UserType>::FromTuple(t);
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    static_assert(sizeof(UserType) < 0, "Must be overriden for user types");
    return {};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    static_assert(sizeof(UserType) < 0, "Must be overriden for user types");
    return {};
  }

  static serialization_type FromTuple(const std::tuple<Members...>& values) {
    return FromTupleDefaultImpl(
        values, std::make_index_sequence<sizeof...(Members)>());
  }

  template <size_t... I>
  static serialization_type FromTupleDefaultImpl(
      const std::tuple<Members...>& values, std::index_sequence<I...>) {
    return {std::get<I>(values)...};
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    static_assert(HasEqualOp<serialization_type>::value,
                  "Missing == operator for the type");
    return a == b;
  }
};
}  // namespace test_framework

using test_framework::SerializationTrait;
using test_framework::UserSerTrait;
