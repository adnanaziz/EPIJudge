
#pragma once

#include <ostream>
#include <string>
#include <tuple>

#include "fmt_print_fwd.h"
#include "serialization_traits.h"

namespace detail {
template <typename T>
void PrintToImpl(std::ostream& out, const T& x, HasOStreamOpTag) {
  out << x;
}

void PrintToImpl(std::ostream& out, bool b, HasOStreamOpTag) {
  out << (b ? "true" : "false");
}

template <typename T>
void PrintToImpl(std::ostream& out, const T& x, HasNoOStreamOpTag) {
  std::string type_name = typeid(T).name();
  // Some compilers prepend typename with a length of the string
  auto name_begin = std::find_if_not(type_name.begin(), type_name.end(),
                                     [](char c) { return std::isdigit(c); });
  out << "<<<missing operator<<(std::ostream&, "
      << std::string(name_begin, type_name.end()) << ")>>>";
}

template <size_t Idx, typename TupleT>
struct TuplePrintHelper {
  static void PrintTo(std::ostream& out, const TupleT& x) {
    if (Idx < std::tuple_size<TupleT>::value) {
      out << ", ";
    }
    ::PrintTo(out, std::get<std::tuple_size<TupleT>::value - Idx>(x));
    TuplePrintHelper<Idx - 1, TupleT>::PrintTo(out, x);
  }
};

template <typename TupleT>
struct TuplePrintHelper<0, TupleT> {
  static void PrintTo(std::ostream& out, const TupleT& x) {}
};

template <typename... Args>
void PrintToImpl(std::ostream& out, const std::tuple<Args...>& x,
                 HasNoOStreamOpTag) {
  out << '(';
  TuplePrintHelper<sizeof...(Args), std::tuple<Args...>>::PrintTo(out, x);
  out << ')';
};

template <typename T1, typename T2>
void PrintToImpl(std::ostream& out, const std::pair<T1, T2>& x,
                 HasNoOStreamOpTag) {
  out << '(';
  PrintTo(out, x.first);
  out << ", ";
  PrintTo(out, x.second);
  out << ')';
};

template <typename T>
void PrintToImpl(std::ostream& out, const T& x, HasBeginEndTag) {
  using std::begin;
  using std::end;

  out << "[";
  bool first = true;
  for (auto it = begin(x); it != end(x); ++it) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    PrintTo(out, *it);
  }

  out << "]";
};

template <typename BinaryTreeT>
void PrintToImpl(std::ostream& out, const BinaryTreeT& x, IsBinaryTreeTag) {
  out << BinaryTreeToString(x);
}

struct FormatterArgsTerminator {
  friend std::ostream& operator<<(std::ostream& out,
                                  const FormatterArgsTerminator& terminator) {
    return out;
  }
};

void FmtStrImpl(std::ostream& out, const std::string& fmt, size_t idx) {
  throw std::runtime_error("FmtStr: fmt=\"" + fmt +
                           "\": too many value placeholders provided");
}

template <typename Head, typename... Tail>
void FmtStrImpl(std::ostream& out, const std::string& fmt, size_t idx,
                const Head& next_value, const Tail&... values) {
  enum { NORMAL, ESCAPE } state = NORMAL;

  for (; idx < fmt.size(); idx++) {
    switch (state) {
      case NORMAL:
        if (fmt[idx] == '{') {
          state = ESCAPE;
        } else {
          out << fmt[idx];
        }
        break;

      case ESCAPE:
        if (fmt[idx] == '{') {
          out << fmt[idx];
          state = NORMAL;
        } else if (fmt[idx] == '}') {
          PrintTo(out, next_value);
          FmtStrImpl(out, fmt, idx + 1, values...);
          return;
        } else {
          throw std::runtime_error(
              std::string("FmtStr: fmt=\"" + fmt + "\": unexpected char ") +
              fmt[idx] + " at " + std::to_string(idx));
        }
    }
  }

  if (state == ESCAPE) {
    throw std::runtime_error("FmtStr: fmt=\"" + fmt +
                             "\": unexpected end of fmt string");
  }

  if (!std::is_same<Head, FormatterArgsTerminator>::value) {
    throw std::runtime_error("FmtStr: fmt=\"" + fmt +
                             "\": too many values provided");
  }
}
}  // namespace detail

template <typename T>
std::ostream& PrintTo(std::ostream& out, const T& x) {
  using Tag = std::conditional_t<
      HasOStreamOp<T>::value, HasOStreamOpTag,
      std::conditional_t<
          HasBeginEnd<T>::value, HasBeginEndTag,
          std::conditional_t<IsBinaryTree<T>::value, IsBinaryTreeTag,
                             HasNoOStreamOpTag>>>;

  detail::PrintToImpl(out, x, Tag());
  return out;
}

template <typename... Args>
std::string FmtStr(const std::string& fmt, const Args&... args) {
  std::stringstream ss;
  detail::FmtStrImpl(ss, fmt, 0, args..., detail::FormatterArgsTerminator{});
  return ss.str();
}
