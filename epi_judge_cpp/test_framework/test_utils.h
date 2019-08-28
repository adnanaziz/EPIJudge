
#pragma once

#include <algorithm>
#include <cctype>
#include <fstream>
#include <future>
#include <iostream>
#include <iterator>
#include <memory>
#include <numeric>
#include <regex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "platform.h"
#include "serialization_traits.h"
#include "test_failure.h"
#include "test_utils_console.h"
#include "test_utils_meta.h"
#include "timeout_exception.h"
namespace test_framework {
namespace test_utils {
static char pardir[]{'.', '.', platform::PathSep(), '\0'};

/**
 * Serialized type name can contain multiple comments, enclosed into brackets.
 * This function removes all such comments.
 */
std::string FilterBracketComments(const std::string& type) {
  static const std::regex bracket_enclosed_comment(R"((\[[^\]]*\]))");
  std::string result = std::regex_replace(type, bracket_enclosed_comment, "");
  result.erase(std::remove_if(std::begin(result), std::end(result), isspace),
               std::end(result));
  return result;
}

/**
 * Helper function, see MatchFunctionSignature().
 * Is used for the template parameter pack expansion trick.
 * @tparam ArgTuple - function argument types, passed as inside std::tuple
 * type.
 * @tparam I - increasing integer sequence with the same number of integers as
 * ArgTuple size.
 * @param begin - begin iterator of the test data header entries.
 * It must be ensured, that (begin + (tuple size of ArgTuple) - 1) is a valid
 * iterator.
 */
template <typename ArgTuple, size_t... I>
void MatchFunctionSignatureImpl(
    std::vector<std::string>::const_iterator begin,
    std::index_sequence<I...> /*unused*/) {
  int mismatch_idx = FirstFalseArg(
      FilterBracketComments(*(begin + I)) ==
      SerializationTrait<std::tuple_element_t<I, ArgTuple>>::Name()...);

  if (mismatch_idx != 0) {
    throw std::runtime_error("Argument mismatch at index " +
                             std::to_string(mismatch_idx));
  }
};

/**
 * This functions deserializes tested function arguments
 * from their string representation.
 * @tparam ArgTuple - tested function argument types, passed inside std::tuple
 * type.
 * @see ParseSerializedArgs()
 * @tparam I - increasing integer sequence with the same number of integers as
 * ArgTuple size.
 * @param begin - begin iterator of the vector,
 * containing arguments in their string representation.
 * It must be ensured, that (begin + (tuple size of ArgTuple) - 1)
 * is a valid iterator.
 * @return deserialized function arguments, packed into std::tuple.
 */
template <typename ArgTuple, size_t... I>
decltype(auto) ParseSerializedArgsImpl(
    std::vector<std::string>::const_iterator begin,
    std::index_sequence<I...> /*unused*/) {
  using json = nlohmann::json;
  return std::make_tuple(
      SerializationTrait<std::tuple_element_t<I, ArgTuple>>::Parse(
          json::parse(*(begin + I)))...);
};
}  // namespace test_utils

std::string GetDefaultTestDataDirPath() {
  static constexpr int kMaxSearchDepth = 4;

  std::string path = "test_data";
  for (int i = 0; i < kMaxSearchDepth; i++) {
    if (platform::IsDir(path.c_str())) {
      return path;
    }
    path.insert(0, test_utils::pardir);
  }

  throw std::runtime_error(
      "Can't find test data directory. Please start the program with "
      "\"--test_data_dir <path>\" command-line option");
}

std::vector<std::vector<std::string>> SplitTsvFile(
    const std::string& tsv_file) {
  const char kRowDelim = '\n';
  const char kFieldDelim = '\t';

  std::ifstream input_data(tsv_file);
  if (!input_data.is_open()) {
    throw std::runtime_error("Test data file not found");
  }

  std::vector<std::vector<std::string>> result;
  for (std::string row; getline(input_data, row, kRowDelim);) {
    std::vector<std::string> one_test_data_set;
    std::istringstream ss(row);
    for (std::string field; getline(ss, field, kFieldDelim);) {
      one_test_data_set.emplace_back(field);
    }
    result.emplace_back(one_test_data_set);
  }
  return result;
}

std::string GetFilePathInJudgeDir(const std::string& file_name) {
  return GetDefaultTestDataDirPath() + platform::PathSep() +
         std::string(test_utils::pardir) + file_name;
}

/**
 * A functor-like wrapper for SerializationTrait::Equal() function
 */
struct DefaultComparator {
  template <typename T, typename U>
  bool operator()(const T& a, const U& b) const {
    return SerializationTrait<T>::Equal(a, b);
  }
};

/**
 * Compares elements of 2 (multi-dimensional) vectors.
 * Both vectors are sorted (@see CompleteSort()) and
 * then compared with ==.
 */
struct UnorderedComparator {
  template <typename T>
  bool operator()(T a, T b) const {
    CompleteSort(a);
    CompleteSort(b);
    return DefaultComparator{}(a, b);
  }
};

/**
 * This function asserts that the tested function signature matches
 * the one in the test data header. Test function argument types and
 * return type are passed as template arguments.
 *
 * @tparam RetType - test function return type
 *                   (or custom expected value type if provided)
 * @tparam ArgTuple - test function argument types
 * @param begin - begin iterator of the test data header entries
 * @param end - end iterator of the test data header entries
 */
template <typename RetType, typename ArgTuple>
void MatchFunctionSignature(std::vector<std::string>::const_iterator begin,
                            std::vector<std::string>::const_iterator end) {
  constexpr size_t arg_count = std::tuple_size<ArgTuple>::value;
  if (std::distance(begin, end) != arg_count + 1) {
    throw std::runtime_error("Argument type count mismatch: test file = " +
                             std::to_string(std::distance(begin, end) - 1) +
                             ", actual = " + std::to_string(arg_count));
  }

  test_utils::MatchFunctionSignatureImpl<ArgTuple>(
      begin, std::make_index_sequence<arg_count>());

  if (test_utils::FilterBracketComments(*(end - 1)) !=
      SerializationTrait<RetType>::Name()) {
    throw std::runtime_error("Return type mismatch");
  }
};

/**
 * This functions deserializes tested function arguments
 * from their string representation.
 * @tparam ArgTuple - tested function argument types, passed inside std::tuple
 * type.
 * @param begin - begin iterator of the vector,
 * containing arguments in their string representation.
 * @param end - end iterator of the vector,
 * containing arguments in their string representation.
 * @return deserialized function arguments, packed into std::tuple.
 * @throw std::runtime_error if deserialization can't be performed.
 */
template <typename ArgTuple>
decltype(auto) ParseSerializedArgs(
    std::vector<std::string>::const_iterator begin,
    std::vector<std::string>::const_iterator end) {
  constexpr size_t arg_count = std::tuple_size<ArgTuple>::value;
  if (std::distance(begin, end) != arg_count) {
    throw std::runtime_error("Argument count mismatch: test file = " +
                             std::to_string(std::distance(begin, end)) +
                             ", actual = " + std::to_string(arg_count));
  }

  return test_utils::ParseSerializedArgsImpl<ArgTuple>(
      begin, std::make_index_sequence<arg_count>());
}
}  // namespace test_framework

using test_framework::DefaultComparator;
using test_framework::UnorderedComparator;
