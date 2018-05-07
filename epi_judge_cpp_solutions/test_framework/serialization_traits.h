
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
#include "json_parser.h"
#include "test_utils_meta.h"

struct NoSpecializationTag {};

/**
 * SerializationTraits defines a mapping between
 * possible types from a function signature and
 * the ones from test data file.
 * It also adds a primitive type reflexion.
 *
 * For adding a new type one should
 * create a template specialization
 * for SerializationTraits structure and
 * implement Name(), Parse(), JsonParse(),
 * and equals() static methods and
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
struct SerializationTraits : NoSpecializationTag {
  using serialization_type = T;

  static constexpr const char* Name() { return typeid(T).name(); }

  static void Parse(const std::string& str) {
    static_assert(sizeof(T) < 0, "Unsupported type");
  }

  static void JsonParse(const json_parser::Json& json_object) {
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
using HasSerializationTraitsSpecialization = std::integral_constant<
    bool,
    !std::is_base_of<NoSpecializationTag, SerializationTraits<T>>::value>;

/**
 * void specialization.
 * It is used when tested function has void return type.
 */
template <>
struct SerializationTraits<void, void> {
  using serialization_type = void;

  static constexpr const char* Name() { return "void"; }

  static void Parse(const std::string& str) {
    throw std::runtime_error("Can't parse void");
  }

  static void JsonParse(const json_parser::Json& json_object) {
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
struct SerializationTraits<VoidPlaceholder, void>
    : SerializationTraits<void, void> {
  using serialization_type = VoidPlaceholder;
};

/**
 * Signed and unsigned 8-, 16-, and 32-bits integer specialization.
 */
template <typename T>
struct SerializationTraits<
    T, std::enable_if_t<std::is_integral<T>::value && sizeof(T) <= 4 &&
                        is_pure_type<T>::value>> {
  using serialization_type = int32_t;

  static constexpr const char* Name() { return "int"; }

  static T Parse(const std::string& str) {
    try {
      return static_cast<T>(std::stoi(str));
    } catch (std::invalid_argument&) {
      throw std::runtime_error("Int parser: conversion error");
    } catch (std::out_of_range&) {
      throw std::runtime_error("Int parser: conversion error: out of range");
    }
  }

  static T JsonParse(const json_parser::Json& json_object) {
    if (json_object.is_number()) {
      return static_cast<T>(json_object.int_value());
    } else {
      throw std::runtime_error("Int parser: conversion error");
    }
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
struct SerializationTraits<
    T, std::enable_if_t<std::is_integral<T>::value && sizeof(T) == 8 &&
                        std::is_signed<T>::value && is_pure_type<T>::value>> {
  using serialization_type = int64_t;

  static constexpr const char* Name() { return "long"; }

  static serialization_type Parse(const std::string& str) {
    try {
      return std::stoll(str);
    } catch (std::invalid_argument&) {
      throw std::runtime_error("Long parser: conversion error");
    } catch (std::out_of_range&) {
      throw std::runtime_error("Long parser: conversion error: out of range");
    }
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    if (json_object.is_number()) {
      return static_cast<serialization_type>(json_object.int_value());
    } else {
      throw std::runtime_error("Long parser: conversion error");
    }
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(std::min<serialization_type>(
        std::abs(x), std::numeric_limits<int>::max()))};
  }

  static bool Equal(serialization_type a, serialization_type b) {
    return a == b;
  }
};

/**
 * Unsigned 64-bit integer specialization.
 */
template <typename T>
struct SerializationTraits<
    T,
    std::enable_if_t<std::is_integral<T>::value && sizeof(T) == 8 &&
                     !std::is_signed<T>::value && is_pure_type<T>::value>> {
  using serialization_type = uint64_t;

  static constexpr const char* Name() { return "long"; }

  static serialization_type Parse(const std::string& str) {
    try {
      return std::stoull(str);
    } catch (std::invalid_argument&) {
      throw std::runtime_error("Long parser: conversion error");
    } catch (std::out_of_range&) {
      throw std::runtime_error("Long parser: conversion error: out of range");
    }
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    if (json_object.is_number()) {
      return static_cast<serialization_type>(json_object.int_value());
    } else {
      throw std::runtime_error("Long parser: conversion error");
    }
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(
        std::min<serialization_type>(x, std::numeric_limits<int>::max()))};
  }

  static bool Equal(serialization_type a, serialization_type b) {
    return a == b;
  }
};

/**
 * Float specialization.
 */
template <>
struct SerializationTraits<float, void> {
  using serialization_type = float;

  static constexpr const char* Name() { return "float"; }

  static serialization_type Parse(const std::string& str) {
    try {
      return std::stof(str);
    } catch (std::invalid_argument&) {
      throw std::runtime_error("Float parser: conversion error");
    } catch (std::out_of_range&) {
      throw std::runtime_error(
          "Float parser: conversion error: out of range");
    }
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    if (json_object.is_number()) {
      return static_cast<serialization_type>(json_object.number_value());
    } else {
      throw std::runtime_error("Float parser: conversion error");
    }
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(std::min<serialization_type>(
        std::abs(x), std::numeric_limits<int>::max()))};
  }

  static bool Equal(serialization_type a, serialization_type b) {
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
struct SerializationTraits<double, void> {
  using serialization_type = double;

  static constexpr const char* Name() { return "float"; }

  static serialization_type Parse(const std::string& str) {
    try {
      return std::stod(str);
    } catch (std::invalid_argument&) {
      throw std::runtime_error("Double parser: conversion error");
    } catch (std::out_of_range&) {
      throw std::runtime_error(
          "Double parser: conversion error: out of range");
    }
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    if (json_object.is_number()) {
      return json_object.number_value();
    } else {
      throw std::runtime_error("Double parser: conversion error");
    }
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {arg_name};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {static_cast<int>(std::min<serialization_type>(
        std::abs(x), std::numeric_limits<int>::max()))};
  }

  static bool Equal(serialization_type a, serialization_type b) {
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
struct SerializationTraits<bool, void> {
  using serialization_type = bool;

  static constexpr const char* Name() { return "bool"; }

  static serialization_type Parse(const std::string& str) {
    if (str == "true" || str == "True") {
      return true;
    }
    if (str == "false" || str == "False") {
      return false;
    }
    throw std::runtime_error("Bool parser: conversion error from " + str);
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    if (json_object.is_bool()) {
      return json_object.bool_value();
    } else {
      throw std::runtime_error("Bool parser: conversion error");
    }
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    // TODO Should we generate any metric for booleans at all?
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
struct SerializationTraits<std::string, void> {
  using serialization_type = std::string;

  static constexpr const char* Name() { return "string"; }

  static const std::string& Parse(const std::string& str) { return str; }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    if (json_object.is_string()) {
      return json_object.string_value();
    } else {
      throw std::runtime_error("String parser: conversion error");
    }
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
struct SerializationTraits<std::vector<Inner>, void> {
  using inner_traits = SerializationTraits<Inner>;
  using serialization_type =
      std::vector<typename inner_traits::serialization_type>;

  static const char* Name() {
    static std::string s = FmtStr("array({})", inner_traits::Name());
    return s.c_str();
  }

  static serialization_type Parse(const std::string& str) {
    std::string err;

    auto json_object = json_parser::Json::parse(str, err);
    if (!err.empty()) {
      throw std::runtime_error("Array parser: JSON: " + err);
    }

    return JsonParse(json_object);
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    if (!json_object.is_array()) {
      throw std::runtime_error("Array parser: expected array");
    }

    serialization_type result;

    for (auto& inner : json_object.array_items()) {
      result.push_back(inner_traits::JsonParse(inner));
    }

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
                      inner_traits::Equal);
  }
};

/**
 * Helper class for container specializations.
 */
template <template <typename...> class Container, typename Inner>
struct ArrayBasedTypeSerTraits : SerializationTraits<std::vector<Inner>> {
  using serialization_type = Container<Inner>;

  static serialization_type Parse(const std::string& str) {
    auto v = SerializationTraits<std::vector<Inner>>::Parse(str);
    return FromVector(v);
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    auto v = SerializationTraits<std::vector<Inner>>::JsonParse(json_object);
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
                      SerializationTraits<Inner>::Equal);
  }
};

/**
 * std::deque specialization.
 */
template <typename Inner>
struct SerializationTraits<std::deque<Inner>, void>
    : ArrayBasedTypeSerTraits<std::deque, Inner> {};

/**
 * std::set specialization.
 */
template <typename Inner>
struct SerializationTraits<std::set<Inner>, void>
    : ArrayBasedTypeSerTraits<std::set, Inner> {
  using inner_traits = SerializationTraits<Inner>;

  static const char* Name() {
    static std::string s = FmtStr("set({})", inner_traits::Name());
    ;
    return s.c_str();
  }
};

/**
 * std::unordered_set specialization.
 */
template <typename Inner>
struct SerializationTraits<std::unordered_set<Inner>, void>
    : ArrayBasedTypeSerTraits<std::unordered_set, Inner> {
  using inner_traits = SerializationTraits<Inner>;

  static const char* Name() {
    static std::string s = FmtStr("set({})", inner_traits::Name());
    ;
    return s.c_str();
  }
};

/**
 * std::tuple specialization
 */
template <typename... TupleTypes>
struct SerializationTraits<std::tuple<TupleTypes...>, void> {
  using tuple_type = std::tuple<TupleTypes...>;
  using serialization_type = std::tuple<
      typename SerializationTraits<TupleTypes>::serialization_type...>;

  template <size_t Begin, size_t End>
  using this_sub_tuple_t = sub_tuple_t<tuple_type, Begin, End>;

  using this_tuple_size = std::tuple_size<tuple_type>;
  using index_sequence = std::make_index_sequence<this_tuple_size::value>;

  template <size_t I>
  using ith_item_t = std::tuple_element_t<I, tuple_type>;

  template <size_t I>
  using ith_item_trait = SerializationTraits<ith_item_t<I>>;

  static const char* Name() {
    static std::string s = FmtStr("tuple({})", InnerTypesName());
    return s.c_str();
  }

  static serialization_type Parse(const std::string& str) {
    std::string err;

    auto json_object = json_parser::Json::parse(str, err);
    if (!err.empty()) {
      throw std::runtime_error("Tuple parser: JSON: " + err);
    }

    return JsonParse(json_object);
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    if (!json_object.is_array()) {
      throw std::runtime_error("Tuple parser: expected array");
    }

    auto& arr = json_object.array_items();

    if (arr.size() != this_tuple_size::value) {
      throw std::runtime_error(
          FmtStr("Tuple parser: invalid item count: expected {}, actual {}",
                 this_tuple_size::value, arr.size()));
    }

    return JsonArrayToTuple(arr, index_sequence());
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
    return Concatenate(",", SerializationTraits<TupleTypes>::Name()...);
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
      const typename json_parser::Json::array& json_arr,
      std::index_sequence<I...> /*unused*/) {
    return std::make_tuple(ith_item_trait<I>::JsonParse(json_arr[I])...);
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
struct BinaryTreeSerializationTraitsHelper {
  template <typename Node, typename Parent>
  static void InitParent(const Node& n, const Parent& p) {}
};

template <>
struct BinaryTreeSerializationTraitsHelper<true> {
  template <typename Node, typename Parent>
  static void InitParent(Node& n, Parent& p) {
    n->parent = p;
  }
};

template <typename T, bool HasParent>
struct BinaryTreeSerializationTraits;

/**
 * Common implementation for binary tree specializations.
 * @tparam SmartPtrT - binary tree smart pointer type
 *                  (usually smart_ptr or unique_ptr).
 * @tparam NodeT - binary tree node type.
 * @tparam KeyT - node key type.
 * @tparam HasParent - affects the parent pointer initialization.
 */
template <template <typename...> class SmartPtrT,
          template <typename...> class NodeT, typename KeyT, bool HasParent,
          typename... MsvcWorkaround>
struct BinaryTreeSerializationTraits<
    SmartPtrT<NodeT<KeyT>, MsvcWorkaround...>, HasParent> {
  using key_traits = SerializationTraits<KeyT>;
  using node_type = NodeT<typename key_traits::serialization_type>;
  using serialization_type = SmartPtrT<node_type>;

  static const char* Name() {
    static std::string s = FmtStr("binary_tree({})", key_traits::Name());
    return s.c_str();
  }

  static serialization_type Parse(const std::string& str) {
    auto v = SerializationTraits<std::vector<std::string>>::Parse(str);
    return BuildTreeFromVector(v);
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    auto v =
        SerializationTraits<std::vector<std::string>>::JsonParse(json_object);
    return BuildTreeFromVector(v);
  }

  static std::vector<std::string> GetMetricNames(
      const std::string& arg_name) {
    return {FmtStr("size({})", arg_name), FmtStr("height({})", arg_name)};
  }

  static std::vector<int> GetMetrics(const serialization_type& x) {
    return {BinaryTreeSize(x), BinaryTreeHeight(x)};
  }

  static serialization_type BuildTreeFromVector(
      const std::vector<std::string>& data) {
    if (data.empty()) {
      throw std::runtime_error("Tree parser: missing data");
    }

    std::vector<node_type*> nodes;

    for (auto& x : data) {
      nodes.emplace_back(x == "null" ? nullptr
                                     : new node_type{key_traits::Parse(x)});
    }
    std::vector<node_type*> candidate_children(std::rbegin(nodes),
                                               std::rend(nodes));
    auto root = serialization_type(candidate_children.back());
    candidate_children.pop_back();

    using traits_helper = BinaryTreeSerializationTraitsHelper<HasParent>;

    for (const auto& node : nodes) {
      if (node) {
        if (!candidate_children.empty()) {
          node->left = serialization_type(candidate_children.back());
          if (node->left) {
            traits_helper::InitParent(node->left, node);
          }
          candidate_children.pop_back();
        } else {
          node->left = nullptr;
        }
        if (!candidate_children.empty()) {
          node->right = serialization_type(candidate_children.back());
          if (node->right) {
            traits_helper::InitParent(node->right, node);
          }
          candidate_children.pop_back();
        } else {
          node->right = nullptr;
        }
      }
    }
    return root;
  }

  static bool Equal(const serialization_type& a,
                    const serialization_type& b) {
    return EqualBinaryTrees(a, b);
  }
};

#define DECLARE_BINARY_TREE_TYPE(KeyType, NodePtrType, HasParent) \
  template <typename KeyType>                                     \
  struct SerializationTraits<NodePtrType>                         \
      : BinaryTreeSerializationTraits<NodePtrType, HasParent> {}; \
  namespace detail {                                              \
  template <typename KeyType>                                     \
  struct IsBinaryTreeImpl<NodePtrType> : std::true_type {};       \
  }  // namespace

/**
 * A specialization for handling types with modifiers.
 * Since we use full template specializations,
 * a certain specialization won't be picked up by compiler
 * if the type has an additional modifier (reference, for example).
 *
 * So, having SerializationTraits<std::string> specialization,
 * it would be dropped if we try to instantiate
 * SerializationTraits<const std::string&>.
 *
 * This partial specialization solves the following problem
 * by instructing a compiler that serialization traits
 * for a type with modifiers are the same as
 * for the pure type (without modifiers).
 * For pure types this specialization
 * is disabled by enable_if.
 */
template <typename T>
struct SerializationTraits<T, std::enable_if_t<!is_pure_type<T>::value>>
    : SerializationTraits<remove_ref_cv_t<T>> {};

/**
 * Helper function for writing a serialization traits specialization
 * for simple user types (plain structures without pointers and
 * other non-trivial attributes). The user structure would be
 * encoded as a tuple in test data.
 *
 * Usage example:
 * struct Point {int x, y;};
 * template <>
 * struct SerializationTraits<Point>:
 *     UserSerTraits<Point, int, int> {};
 *
 * At first, data is parsed into std::tuple.
 * Then the target object is constructed from tuple
 * (@see UserSerTraits::FromTuple).
 * If the default implementation of UserSerTraits::FromTuple is not suitable,
 * one can provide their own implementation
 * in the SerializationTraits<UserType> specialization.
 * It will be picked up using CRTP technique.
 *
 * @tparam UserType - target user type.
 * @tparam Members - a list of argument types, from which
 * it must be possible to construct an instance of UserType
 * either by calling a constructor or using aggregate initialization.
 */
template <typename UserType, typename... Members>
struct UserSerTraits : SerializationTraits<std::tuple<Members...>> {
  using serialization_type = UserType;

  static serialization_type Parse(const std::string& str) {
    auto t = SerializationTraits<std::tuple<Members...>>::Parse(str);
    return SerializationTraits<UserType>::FromTuple(t);
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    auto t =
        SerializationTraits<std::tuple<Members...>>::JsonParse(json_object);
    return SerializationTraits<UserType>::FromTuple(t);
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
