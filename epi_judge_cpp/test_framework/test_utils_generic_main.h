// @library
#pragma once

#include <chrono>
#include <stdexcept>
#include <string>
#include <vector>

#include "generic_test_handler.h"
#include "test_utils.h"

/**
 * Common main() function for all test programs based on the generic test
 * framework.
 * The normal way of adding it is to include this file in the end of tested
 * file.
 * Before doing so, TEST_FUNC_NAME and TEST_FILE_PATH
 * and optionally RESULT_COMPARATOR macros must be defined
 */
template <typename Function, typename Comparator = DefaultComparator>
void generic_test_main(int argc, char* argv[], const std::string& filename,
                       Function func, Comparator comp = {}) {
  // Enables automatic flushing of the output stream after any output
  // operation.
  std::cout.setf(std::ios::unitbuf);

  std::string test_data_dir = kDefaultTestDataDir;
  bool stop_on_error = true;

  std::vector<std::string> commandline_args(argv + 1, argv + argc);
  try {
    for (int i = 0; i < commandline_args.size(); ++i) {
      if (commandline_args[i] == "--test_data_dir") {
        if (i + 1 >= commandline_args.size()) {
          throw std::runtime_error("Missing param for --test_data_dir");
        }
        test_data_dir = commandline_args[i + 1];
        ++i;
      } else if (commandline_args[i] == "--run_all_tests") {
        stop_on_error = false;
      } else {
        throw std::runtime_error("Unrecognized argument: " +
                                 commandline_args[i]);
      }
    }

    if (test_data_dir.empty()) {
      test_data_dir += '.';
    }
    if (test_data_dir.back() != '/') {
      test_data_dir += '/';
    }
  } catch (std::runtime_error& e) {
    std::cerr << std::endl << "Critical error: " << e.what() << std::endl;
  }

  GenericTestHandler<Function, Comparator> test_handler(func, comp);
  using namespace std::chrono_literals;
  RunTests(test_data_dir + filename, test_handler, 0s, stop_on_error);
}
