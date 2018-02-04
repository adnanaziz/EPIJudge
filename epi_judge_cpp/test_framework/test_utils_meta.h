// @library
#pragma once

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <vector>

#include "test_timer.h"

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
int FirstFalseArg() { return 0; }

/**
 * This function takes a variable number of boolean arguments
 * and returns the index of the first false argument (starting from 1)
 * or 0 if there's no false argument.
 * @return index of the first false argument or 0
 */
template <typename... Bools>
int FirstFalseArg(bool b, Bools... tail) {
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

  static constexpr bool HasTimerHook() { return false; }

  template <typename Func, typename... ArgsFwd>
  static ReturnT InvokeWithTimer(Func& f, TestTimer& timer,
                                 ArgsFwd&&... args) {
    timer.Start();
    OnScopeExit timer_stopper(std::bind(&TestTimer::Stop, &timer));

    return f(std::forward<ArgsFwd>(args)...);
  }
};

/**
 * Hook for function wrappers with custom timing.
 */
template <typename ReturnT, typename... ArgsT>
struct FunctionalTraits<ReturnT (*)(TestTimer&, ArgsT...)> {
  using return_t = ReturnT;
  using arg_tuple_t = std::tuple<ArgsT...>;

  static constexpr bool HasTimerHook() { return true; }

  template <typename Func, typename... ArgsFwd>
  static ReturnT InvokeWithTimer(Func& f, TestTimer& timer,
                                 ArgsFwd&&... args) {
    // timer must be started by f
    OnScopeExit timer_stopper(std::bind(&TestTimer::Stop, &timer));

    return f(timer, std::forward<ArgsFwd>(args)...);
  }
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
 * @see Print()
 */
template <typename T>
void PrintImpl(const T& value);

template <typename T>
struct PrintHelper {
  static void Print(const T& value) { std::cout << value; }
};

template <typename T>
struct PrintHelper<std::vector<T>> {
  static void Print(const std::vector<T>& value) {
    std::cout << "[";
    if (!value.empty()) {
      PrintImpl(value.front());
    }
    for (int i = 1; i < size(value); ++i) {
      std::cout << ", ";
      PrintImpl(value[i]);
    }
    std::cout << "]";
  }
};

template <size_t Idx, typename TupleT>
struct TuplePrintHelper {
  static void Print(const TupleT& value) {
    if (Idx < std::tuple_size<TupleT>::value) {
      std::cout << ", ";
    }
    PrintImpl(std::get<std::tuple_size<TupleT>::value - Idx>(value));
    TuplePrintHelper<Idx - 1, TupleT>::Print(value);
  }
};

template <typename TupleT>
struct TuplePrintHelper<0, TupleT> {
  static void Print(const TupleT& value) {}
};

template <typename... Args>
struct PrintHelper<std::tuple<Args...>> {
  static void Print(const std::tuple<Args...>& value) {
    std::cout << "(";
    TuplePrintHelper<sizeof...(Args), std::tuple<Args...>>::Print(value);
    std::cout << ")";
  }
};

template <typename T>
void PrintImpl(const T& value) {
  PrintHelper<T>::Print(value);
}

/**
 * Generic print function.
 * Able to print out vectors, tuples,
 * and everything that has operator<<() overloading.
 * TODO Rename to Println
 */
template <typename T>
void Print(const T& value) {
  PrintImpl(value);
  std::cout << std::endl;
}
