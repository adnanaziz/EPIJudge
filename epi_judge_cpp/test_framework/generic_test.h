// @library
#pragma once

#include <chrono>
#include <stdexcept>
#include <string>
#include <vector>

#include "generic_test_handler.h"
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
                           const std::chrono::seconds& timeout,
                           const std::string& test_data_file,
                           Function test_func, Comparator comparator,
                           const std::vector<std::string>& param_names) {
  // Enables automatic flushing of the output stream after any output
  // operation.
  std::cout.setf(std::ios::unitbuf);

  try {
    TestConfig config = TestConfig::FromCommandLine(test_data_file, timeout,
                                                    commandline_args);

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
  using handler_t = GenericTestHandler<Function, Comparator>;

  auto test_data = SplitTsvFile(config.test_data_dir + config.test_data_file);
  handler.ParseSignature(test_data[0]);

  int test_nr = 0;
  int tests_passed = 0;
  const int total_tests = static_cast<int>(test_data.size() - 1);
  std::vector<std::chrono::microseconds> durations;

  TestResult result = FAILED;
  for (auto test_case = test_data.begin() + 1; test_case != test_data.end();
       ++test_case) {
    test_nr++;

    // Since the last field of test_data is test_explanation, which is not
    // used for running test, we extract that here.
    const std::string test_explanation = std::move(test_case->back());
    test_case->pop_back();

    TestTimer test_timer;
    TestFailure test_failure;

    try {
      test_timer = handler.RunTest(config.timeout, *test_case);
      result = PASSED;
      tests_passed++;
      durations.push_back(test_timer.GetMicroseconds());
    } catch (TestFailure& e) {
      result = FAILED;
      test_failure = e;
    } catch (TimeoutException& e) {
      result = TIMEOUT;
    } catch (std::runtime_error& e) {
      throw;
    } catch (std::exception& e) {
      result = UNKNOWN_EXCEPTION;
      test_failure = TestFailure(typeid(e).name())
                         .WithProperty(PropertyName::EXCEPTION_MESSAGE,
                                       std::string(e.what()));
    } catch (...) {
      result = UNKNOWN_EXCEPTION;
      test_failure = TestFailure("???");
    }

    PrintTestInfo(result, test_nr, total_tests, test_failure.GetDescription(),
                  test_timer);

    if (result != PASSED && config.stop_on_error) {
      if (!handler.ExpectedIsVoid()) {
        test_case->pop_back();
      }
      if (test_explanation != "TODO" && !test_explanation.empty()) {
        test_failure.WithProperty(PropertyName::EXPLANATION,
                                  test_explanation);
      }
      PrintFailedTest(handler.ParamNames(), *test_case, test_failure);
      break;
    }
  }

  std::cout << std::endl;

  if (config.stop_on_error) {
    PrintPostRunStats(tests_passed, total_tests, durations);
  }
  return result;
}
