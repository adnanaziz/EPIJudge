// @library
#pragma once

#include <chrono>
#include <stdexcept>
#include <string>
#include <vector>

#include "generic_test_handler.h"
#include "test_config.h"
#include "test_utils.h"

template <typename Function, typename Comparator>
void RunTests(GenericTestHandler<Function, Comparator>& handler,
              const TestConfig& config);

/**
 * The main test starter.
 */
template <typename Function, typename Comparator>
void GenericTestMain(const std::vector<std::string>& commandline_args,

                     const std::string& test_data_file, Function test_func,
                     Comparator comparator,
                     const std::vector<std::string>& param_names) {
  // Enables automatic flushing of the output stream after any output
  // operation.
  std::cout.setf(std::ios::unitbuf);

  try {
    auto config =
        TestConfig::FromCommandLine(test_data_file, commandline_args);

    GenericTestHandler<Function, Comparator> test_handler(
        test_func, comparator, param_names);
    RunTests(test_handler, config);
  } catch (std::runtime_error& e) {
    std::cerr << std::endl << "Critical error: " << e.what() << std::endl;
  }
}

template <typename Function, typename Comparator>
void RunTests(GenericTestHandler<Function, Comparator>& handler,
              const TestConfig& config) {
  using handler_t = GenericTestHandler<Function, Comparator>;

  auto test_data = SplitTsvFile(config.test_data_dir + config.test_data_file);
  handler.ParseSignature(test_data[0]);

  int test_nr = 0;
  int tests_passed = 0;
  const int total_tests = static_cast<int>(test_data.size() - 1);
  std::vector<std::chrono::microseconds> durations;

  for (auto test_case = test_data.begin() + 1; test_case != test_data.end();
       ++test_case) {
    test_nr++;

    // Since the last field of test_data is test_explanation, which is not
    // used for running test, we extract that here.
    const std::string test_explanation = std::move(test_case->back());
    test_case->pop_back();

    TestResult result = FAILED;
    typename handler_t::test_output_t test_output;
    std::string diagnostic;

    try {
      test_output = InvokeWithTimeout(
          config.timeout,
          std::bind(&handler_t::RunTest, &handler, std::ref(*test_case)));

      result = test_output.comparison_result ? PASSED : FAILED;

    } catch (TestFailureException& e) {
      result = FAILED;
      diagnostic = e.what();
    } catch (TimeoutException& e) {
      result = TIMEOUT;
    } catch (std::runtime_error& e) {
      throw;
    } catch (std::exception& e) {
      result = UNKNOWN_EXCEPTION;
      diagnostic = std::string(typeid(e).name()) + ": " + e.what();
    } catch (...) {
      result = UNKNOWN_EXCEPTION;
      diagnostic = "???";
    }

    PrintTestInfo(result, test_nr, total_tests, diagnostic,
                  test_output.timer);

    if (result == PASSED) {
      tests_passed++;
    }
    if (test_output.timer.HasValidResult()) {
      durations.emplace_back(test_output.timer.GetMicroseconds());
    }
    if (result != PASSED && config.stop_on_error) {
      if (!handler.ExpectedIsVoid()) {
        test_case->pop_back();
      }
      PrintFailedTest(handler.ParamNames(), *test_case, test_output,
                      test_explanation);
      break;
    }
  }

  std::cout << std::endl;

  if (config.stop_on_error) {
    PrintPostRunStats(tests_passed, total_tests, durations);
  }
}
