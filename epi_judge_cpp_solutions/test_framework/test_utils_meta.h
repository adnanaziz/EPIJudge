
#pragma once

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <vector>

/**
 * Some forward declarations
 */
class TimedExecutor;
class TestTimer;

/**
 * Various tag types
 */
struct HasExecutorHookTag {};
struct HasNoExecutorHookTag {};

struct HasEqualOpTag {};
struct HasNoEqualOpTag {};

struct HasOStreamOpTag {};
struct HasNoOStreamOpTag {};

struct HasBeginEndTag {};
struct HasNoBeginEndTag {};

struct IsBinaryTreeTag {};
struct IsNotBinaryTreeTag {};

/**
 * Meta function that removes all modifiers (const, volatile, ref) from T
 */
template <typename T>
using remove_ref_cv_t = std::remove_cv_t<std::remove_reference_t<T>>;

/**
 * Meta function, that resolves into std::true_type if
 * T has no modifiers (const, volatile, ref)
 */
template <typename T>
using is_pure_type = std::is_same<T, remove_ref_cv_t<T>>;

/**
 * @see firstFalseArg(bool, Bools...)
 * Default case for recursion.
 * @return 0
 */
constexpr int FirstFalseArg() { return 0; }

/**
 * This function takes a variable number of boolean arguments
 * and returns the index of the first false argument (starting from 1)
 * or 0 if there's no false argument.
 * @return index of the first false argument or 0
 */
template <typename... Bools>
constexpr int FirstFalseArg(bool b, Bools... tail) {
  if (!b) {
    return 1;
  }
  int result = FirstFalseArg(tail...);
  return result ? result + 1 : 0;
}

struct DefaultComparator;

class OnScopeExit {
 public:
  OnScopeExit(std::function<void()> command) : command_(std::move(command)) {}
  ~OnScopeExit() { command_(); }

 private:
  std::function<void()> command_;
};

/**
 * Simple function reflexion. It is used to deduce argument types and return
 * type of the function.
 * @param Function - the type of the function to be reflected.
 */
template <typename Function>
struct FunctionalTraits;

template <typename ReturnT, typename... ArgsT>
struct FunctionalTraits<ReturnT (*)(ArgsT...)> {
  using return_t = ReturnT;
  using arg_tuple_t = std::tuple<ArgsT...>;

  template <size_t I>
  using ith_arg_t = std::tuple_element_t<I, arg_tuple_t>;

  using executor_hook_tag = HasNoExecutorHookTag;
  static constexpr bool HasExecutorHook() { return false; }
};

/**
 * Hook for function wrappers with custom timing.
 */
template <typename ReturnT, typename... ArgsT>
struct FunctionalTraits<ReturnT (*)(TimedExecutor&, ArgsT...)> {
  using return_t = ReturnT;
  using arg_tuple_t = std::tuple<ArgsT...>;

  template <size_t I>
  using ith_arg_t = std::tuple_element_t<I, arg_tuple_t>;

  using executor_hook_tag = HasExecutorHookTag;
  static constexpr bool HasExecutorHook() { return true; }
};

/**
 * Hook for deprecated hook.
 */
template <typename ReturnT, typename... ArgsT>
struct FunctionalTraits<ReturnT (*)(TestTimer&, ArgsT...)> {
  static_assert(sizeof...(ArgsT) < 0,
                "This program uses deprecated TestTimer hook");
};

/**
 * Simple binary predicate reflexion.
 * Has the same functionality as FunctionalTraits.
 * Additionally has aliases for the 1st and the 2nd argument types.
 * @tparam Function - the type of the function to be reflected.
 */
template <typename Function>
struct BiPredicateTraits;

template <>
struct BiPredicateTraits<DefaultComparator> {
  using arg1_t = void;
  using arg2_t = void;
};

template <typename ReturnT, typename Arg1T, typename Arg2T>
struct BiPredicateTraits<ReturnT (*)(Arg1T, Arg2T)>
    : FunctionalTraits<ReturnT (*)(Arg1T, Arg2T)> {
  using arg1_t = Arg1T;
  using arg2_t = Arg2T;
};

/**
 * @see Concatenate()
 * Default case for recursion.
 * @return empty string
 */
std::string ConcatenateImpl(const std::string& delim, bool first) {
  return {};
}

/**
 * @see Concatenate()
 * @param delim - a delimiter to be inserted between strings
 * @param first - no delimiter is prepended if true
 * @param head - the first of the strings to be concatenated
 * @param tail - any number of strings
 * @return - a concatenation of all strings provided
 */
template <typename... Strings>
std::string ConcatenateImpl(const std::string& delim, bool first,
                            const std::string& head, const Strings&... tail) {
  if (first) {
    return head + ConcatenateImpl(delim, false, tail...);
  }

  return delim + head + ConcatenateImpl(delim, false, tail...);
}

/**
 * This function takes a variable number of string argument and
 * concatenates them, using a delimiter between them.
 * @param delim - a delimiter to be inserted between strings
 * @param strings - any number of strings
 * @return a concatenation of all strings provided
 */
template <typename... Strings>
std::string Concatenate(const std::string& delim, const Strings&... strings) {
  return ConcatenateImpl(delim, true, strings...);
}

/**
 * Meta function that returns an std::tuple with a sublist
 * of types from another tuple.
 * For example,
 * SubTuple<std::tuple<long, int, short, char>, 1, 3>::type is
 * std::tuple<int, short>.
 * @tparam TupleT - tuple argument
 * @tparam Begin - the first index of the sublist of types
 * @tparam End - the one-past-last index of the sublist of types
 */
template <typename TupleT, size_t Begin, size_t End>
class SubTuple {
  static_assert(Begin <= End, "Index error");
  static_assert(End <= std::tuple_size<TupleT>::value, "Index error");

  template <size_t Shift, typename IntSeq>
  struct Impl;

  template <size_t Shift, size_t... I>
  struct Impl<Shift, std::index_sequence<I...>> {
    using type = std::tuple<std::tuple_element_t<Shift + I, TupleT>...>;
  };

 public:
  using type =
      typename Impl<Begin,
                    decltype(std::make_index_sequence<End - Begin>())>::type;
};

/**
 * An alias for SubTuple meta function
 */
template <typename TupleT, size_t Begin, size_t End>
using sub_tuple_t = typename SubTuple<TupleT, Begin, End>::type;

template <typename T>
void CompleteSort(T& x);

template <typename T>
struct CompleteSortImpl {
  static void Sort(const T& x) {}
};

template <typename T>
struct CompleteSortImpl<std::vector<T>> {
  static void Sort(std::vector<T>& v) {
    for (auto& x : v) {
      CompleteSort(x);
    }
    std::sort(std::begin(v), std::end(v));
  }
};

/**
 * Multi-dimensional container sort.
 * If T is vector of vector of ... of vector,
 * then the argument is lexicographically sorted on all levels,
 * starting from the bottom.
 */
template <typename T>
void CompleteSort(T& x) {
  CompleteSortImpl<remove_ref_cv_t<T>>::Sort(x);
}

/**
 * Compares elements of 2 (multi-dimensional) vectors.
 * Both vectors are sorted (@see CompleteSort()) and
 * then compared with ==.
 */
template <typename T>
bool UnorderedComparator(T a, T b) {
  CompleteSort(a);
  CompleteSort(b);
  return a == b;
}

struct VoidPlaceholder {
  friend std::ostream& operator<<(std::ostream& out, VoidPlaceholder x) {
    return out << "void";
  }
};

template <typename T>
using escape_void_t =
    std::conditional_t<std::is_same<T, void>::value, VoidPlaceholder, T>;

/**
 * This function joins elements in vector of vectors
 */
template <typename T>
std::vector<T> FlattenVector(std::vector<std::vector<T>>&& vv) {
  std::vector<T> result;
  for (size_t i = 0; i < vv.size(); i++) {
    result.reserve(result.size() + vv[i].size());
    std::move(begin(vv[i]), end(vv[i]), back_inserter(result));
  }
  return result;
}

namespace detail {
struct No {};
/**
 * @see HasEqualOp
 */
template <typename T, typename EqualTo>
struct HasEqualOpImpl {
  template <typename U, typename V>
  static auto Test(U*) -> decltype(std::declval<U&>() == std::declval<V&>());

  template <typename, typename>
  static auto Test(...) -> No;

  using type = std::integral_constant<
      bool, !std::is_same<decltype(Test<T, EqualTo>(0)), No>::value>;
};

/**
 * @see HasLeftShiftOpImpl
 */
template <typename S, typename T>
struct HasLeftShiftOpImpl {
  template <typename U, typename V>
  static auto Test(U*) -> decltype(std::declval<U&>() << std::declval<V&>());

  template <typename, typename>
  static auto Test(...) -> No;

  using type = std::integral_constant<
      bool, !std::is_same<decltype(Test<S, T>(0)), No>::value>;
};

// Additional namespace is introduced to escape
// the following using declarations
namespace std_import {
using std::begin;
using std::end;

template <typename T>
struct HasBeginEndImpl {
  template <typename U>
  static auto TestBegin(U*) -> decltype(begin(std::declval<U&>()));

  template <typename U>
  static auto TestEnd(U*) -> decltype(end(std::declval<U&>()));

  template <typename>
  static auto TestBegin(...) -> No;

  template <typename>
  static auto TestEnd(...) -> No;

  using type = std::integral_constant<
      bool, !std::is_same<decltype(TestBegin<T>(0)), No>::value &&
                !std::is_same<decltype(TestEnd<T>(0)), No>::value>;
};
}  // namespace std_import

using std_import::HasBeginEndImpl;

template <typename T>
struct IsBinaryTreeImpl {
  using type = std::false_type;
};
}  // namespace detail

/**
 * Check if operator== is defined for T and EqualTo types
 */
template <class T, class EqualTo = T>
using HasEqualOp = typename detail::HasEqualOpImpl<T, EqualTo>::type;
template <typename T, class EqualTo = T>
using EqualOpTag = std::conditional_t<HasEqualOp<T, EqualTo>::value,
                                      HasEqualOpTag, HasNoEqualOpTag>;

/**
 * Check if operator<< is defined for T and U types
 */
template <class T, class U>
using HasLeftShiftOp = typename detail::HasLeftShiftOpImpl<T, U>::type;

/**
 * Check if operator<< is defined for std::ostream and T
 */
template <typename T>
using HasOStreamOp = HasLeftShiftOp<std::ostream, T>;
template <typename T>
using OStreamOpTag = std::conditional_t<HasOStreamOp<T>::value,
                                        HasOStreamOpTag, HasNoOStreamOpTag>;

/**
 * Check if the class has begin()/end() methods
 * (or corresponding free functions).
 * It is assumed these methods return begin/end iterators.
 */
template <typename T>
using HasBeginEnd = typename detail::HasBeginEndImpl<T>::type;
template <typename T>
using BeginEndTag = std::conditional_t<HasBeginEnd<T>::value, HasBeginEndTag,
                                       HasNoBeginEndTag>;

/**
 * Check if T is of a binary tree type
 */
template <typename T>
using IsBinaryTree =
    typename detail::IsBinaryTreeImpl<remove_ref_cv_t<T>>::type;
template <typename T>
using BinaryTreeTag = std::conditional_t<IsBinaryTree<T>::value,
                                         IsBinaryTreeTag, IsNotBinaryTreeTag>;
