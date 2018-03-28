// @library
#pragma once

#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <vector>

#include "generic_test_handler.h"
#include "json_parser.h"
#include "platform.h"
#include "test_config.h"
#include "test_timer.h"
#include "test_utils.h"

template <typename Function, typename Comparator>
TestResult RunTests(GenericTestHandler<Function, Comparator>& handler,
                    const TestConfig& config);

/**
 * The main test starter.
 */
template <typename Function, typename Comparator>
TestResult GenericTestMain(const std::vector<std::string>& commandline_args,
                           const std::string& test_data_file,
                           Function test_func, Comparator comparator,
                           const std::vector<std::string>& param_names) {
  // Enables automatic flushing of the output stream after any output
  // operation.
  std::cout.setf(std::ios::unitbuf);

  std::ifstream config_data(GetFilePathInJudgeDir("config.json"));
  std::string err;
  const json_parser::Json config_override =
      json_parser::Json::parse(std::string{std::istream_iterator<char>(config_data), std::istream_iterator<char>()}, err);

  try {
    TestConfig config = TestConfig::FromCommandLine(
        test_data_file,
        std::chrono::seconds{config_override["timeoutSeconds"].int_value()},
        config_override["numFailedTestsBeforeStop"].int_value(),
        commandline_args);

    platform::SetOutputOpts(config.tty_mode, config.color_mode);

    GenericTestHandler<Function, Comparator> test_handler(
        test_func, comparator, param_names);
    return RunTests(test_handler, config);
  } catch (std::runtime_error& e) {
    std::cerr << std::endl << "Critical error: " << e.what() << std::endl;
    return RUNTIME_ERROR;
  }
}

template <typename Function, typename Comparator>
TestResult RunTests(GenericTestHandler<Function, Comparator>& handler,
                    const TestConfig& config) {
  std::vector<std::vector<std::string>> test_data =
      SplitTsvFile(config.test_data_dir + config.test_data_file);
  handler.ParseSignature(test_data[0]);

  int test_nr = 0;
  int tests_passed = 0;
  const int total_tests = static_cast<int>(test_data.size() - 1);
  std::vector<std::chrono::microseconds> durations;
  TestResult result = FAILED;

  for (auto test_case : std::vector<std::vector<std::string>>{
           test_data.begin() + 1, test_data.end()}) {
    test_nr++;

    // Since the last field of test_data is test_explanation, which is not
    // used for running test, we extract that here.
    const std::string test_explanation = std::move(test_case.back());
    test_case.pop_back();

    TestTimer test_timer;
    TestFailure test_failure;

    try {
      test_timer = handler.RunTest(config.timeout_seconds, test_case);
      result = PASSED;
      ++tests_passed;
      durations.push_back(test_timer.GetMicroseconds());
    } catch (TestFailure& e) {
      result = FAILED;
      test_failure = e;
    } catch (TimeoutException& e) {
      result = TIMEOUT;
      test_timer = e.GetTimer();
    } catch (std::runtime_error& e) {
      throw;
    } catch (std::exception& e) {
      result = UNKNOWN_EXCEPTION;
      test_failure = TestFailure(typeid(e).name())
                         .WithProperty(PropertyName::EXCEPTION_MESSAGE,
                                       std::string(e.what()));
    } catch (...) {
      result = UNKNOWN_EXCEPTION;
      test_failure = TestFailure("Can't get exception information");
    }

    PrintTestInfo(result, test_nr, total_tests, test_failure.GetDescription(),
                  test_timer);

    if (result != PASSED) {
      if (config.verbose) {
        if (!handler.ExpectedIsVoid()) {
          test_case.pop_back();
        }
        if (test_explanation != "TODO" && !test_explanation.empty()) {
          test_failure.WithProperty(PropertyName::EXPLANATION,
                                    test_explanation);
        }
        PrintFailedTest(handler.ParamNames(), test_case, test_failure);
      }
      const int tests_not_passed = test_nr - tests_passed;
      if (tests_not_passed >= config.num_failed_tests_before_stop) {
        break;
      }
    }
  }

  std::cout << std::endl;

  if (config.verbose) {
    PrintPostRunStats(tests_passed, total_tests, durations);
  }
  return result;
}
