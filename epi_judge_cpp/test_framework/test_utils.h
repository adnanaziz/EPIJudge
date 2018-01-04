// @library
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

#include "json_parser.h"
#include "platform.h"
#include "test_failure_exception.h"
#include "test_utils_console.h"
#include "test_utils_meta.h"
#include "test_utils_serialization_traits.h"

namespace {

std::vector<std::vector<std::string>> SplitTsvFile(
    const std::string& data_file) {
  std::ifstream input_data(data_file);
  if (!input_data.is_open()) {
    throw std::runtime_error("Test data file not found");
  }
  const char kRowDelim = '\n';
  const char kFieldDelim = '\t';
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
      SerializationTraits<std::tuple_element_t<I, ArgTuple>>::Name()...);

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
  return std::make_tuple(
      SerializationTraits<std::tuple_element_t<I, ArgTuple>>::Parse(
          *(begin + I))...);
};

std::string GetDefaultTestDataDirPath() {
  constexpr int MAX_SEARCH_DEPTH = 4;
  const std::string ENV_KEY = "EPI_TEST_DATA_DIR";
  const std::string DIR_NAME = "test_data";
  char pardir[]{'.', '.', os::PathSep(), '\0'};
  std::string path;

  const char* env_result = std::getenv(ENV_KEY.c_str());
  if (env_result && env_result[0] != '\0') {
    if (!os::IsDir(env_result)) {
      throw std::runtime_error(ENV_KEY +
                               " environment variable is set to \"" +
                               env_result + "\", but it's not a directory");
    }
    path = env_result;  // Enable RVO optimization
    return path;
  }

  path = DIR_NAME;
  for (int i = 0; i < MAX_SEARCH_DEPTH; i++) {
    if (os::IsDir(path.c_str())) {
      return path;
    }
    path.insert(0, pardir);
  }

  throw std::runtime_error(
      "Can't find test data directory. Specify it with " + ENV_KEY +
      " environment variable (you may need to restart PC) or start the "
      "program with \"--test_data_dir <path>\" command-line option");
}
}  // namespace

template <typename TestHandlerT>
void RunTests(const std::string& test_data_path, TestHandlerT& handler,
              const std::chrono::milliseconds& timeout, bool stop_on_error) {
  std::vector<std::vector<std::string>> test_data =
      SplitTsvFile(test_data_path);
  handler.ParseSignature(test_data[0]);

  int test_nr = 0;
  const int total_tests = static_cast<int>(test_data.size() - 1);
  int tests_passed = 0;
  const bool use_timeout = (timeout != timeout.zero());
  std::vector<std::chrono::microseconds> durations;

  for (std::vector<std::string> test_case :
       std::vector<std::vector<std::string>>{std::next(std::begin(test_data)),
                                             std::end(test_data)}) {
    ++test_nr;

    // Since the last field of test_data is test_explanation, which is not
    // used for running test, we extract that here.
    const std::string test_explanation = std::move(test_case.back());
    test_case.pop_back();

    TestResult result = FAILED;
    typename TestHandlerT::test_output_t test_output;
    std::string diagnostic;

    try {
      if (use_timeout) {
        auto run_test_future = std::async(
            std::launch::async, [&] { return handler.RunTest(test_case); });

        if (run_test_future.wait_for(timeout) == std::future_status::ready) {
          test_output = run_test_future.get();
          result = test_output.comparison_result ? PASSED : FAILED;
        } else {
          result = TIMEOUT;
        }
      } else {
        test_output = handler.RunTest(test_case);
        result = test_output.comparison_result ? PASSED : FAILED;
      }

    } catch (TestFailureException& e) {
      result = FAILED;
      diagnostic = e.what();
    } catch (std::runtime_error&) {
      throw;
    } catch (std::exception& e) {
      result = UNKNOWN_EXCEPTION;
      diagnostic = e.what();
    } catch (...) {
      result = UNKNOWN_EXCEPTION;
      diagnostic = "???";
    }

    // TODO(THL): How to handle the situation when test_result is not valid
    // due to exception?  We handle this in Java and Python.
    PrintTestResult(result, test_nr, total_tests, diagnostic,
                    test_output.timer);
    if (result == PASSED) {
      tests_passed++;
    }
    if (test_output.timer.HasValidResult()) {
      durations.emplace_back(test_output.timer.GetMicroseconds());
    }
    if (result != PASSED && stop_on_error) {
      if (!handler.ExpectedIsVoid()) {
        test_case.pop_back();
      }
      PrintFailedTest(test_case, test_output, test_explanation);
      break;
    }
  }
  std::cout << std::endl;

  if (stop_on_error) {
    if (!durations.empty()) {
      const size_t durations_size = durations.size();
      std::cout << "Average running time: "
                << DurationToString(
                       std::accumulate(std::begin(durations),
                                       std::end(durations),
                                       std::chrono::microseconds::zero()) /
                       durations_size)
                << std::endl;
      std::sort(std::begin(durations), std::end(durations));
      std::cout << "Median running time: "
                << DurationToString(durations_size & 1
                                        ? durations[durations_size / 2]
                                        : (durations[durations_size / 2 - 1] +
                                           durations[durations_size / 2]) /
                                              2)
                << std::endl;
    }
    if (tests_passed < total_tests) {
      std::cout << "*** You've passed " << tests_passed << "/" << total_tests
                << " tests. ***" << std::endl;
    } else {
      std::cout << "*** You've passed ALL tests. Congratulations! ***"
                << std::endl;
    }
  }
}

/**
 * A functor-like wrapper for SerializationTraits::Equal() function
 */
struct DefaultComparator {
  template <typename T, typename U>
  bool operator()(const T& a, const U& b) const {
    return SerializationTraits<T>::Equal(a, b);
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

  MatchFunctionSignatureImpl<ArgTuple>(begin,
                                       std::make_index_sequence<arg_count>());

  if (FilterBracketComments(*(end - 1)) !=
      SerializationTraits<RetType>::Name()) {
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
 * @throws std::runtime_error if deserialization can't be performed.
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

  return ParseSerializedArgsImpl<ArgTuple>(
      begin, std::make_index_sequence<arg_count>());
}
