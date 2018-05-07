
#pragma once

#include <chrono>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "platform.h"
#include "test_utils.h"
#include "tri_bool.h"

std::string GetParam(const std::vector<std::string>& commandline_args,
                     size_t i, const char* arg_name) {
  if (i >= commandline_args.size()) {
    throw std::runtime_error(
        FmtStr("CL: Missing parameter for {}", arg_name));
  }

  return commandline_args[i];
}

void PrintUsageAndExit() {
  const char* usage_string =
      ""
      "usage: <program name> [-h] [--test-data-dir [TEST_DATA_DIR]] "
      "[--no-verbose]\n"
      "                      [--force-tty] [--no-tty] [--force-color] "
      "[--no-color]\n"
      "\n"
      "optional arguments:\n"
      "  -h, --help            show this help message and exit\n"
      "  --test-data-dir [TEST_DATA_DIR] path to test_data directory\n"
      "  --no-verbose          suppress failure description on test failure\n"
      "  --force-tty           enable tty features (like printing output on "
      "the same line) even in case stdout is not a tty device\n"
      "  --no-tty              never use tty features\n"
      "  --force-color         enable colored output even in case stdout is "
      "not a tty device\n"
      "  --no-color            never use colored output\n";
  std::cout << usage_string;
  exit(0);
}

struct TestConfig {
  TestConfig(const std::string& test_file, const std::string& test_data_file,
             const std::chrono::seconds& timeout_seconds,
             int num_failed_tests_before_stop)
      : test_file(test_file),
        test_data_file(test_data_file),
        tty_mode(TriBool::kIndeterminate),
        color_mode(TriBool::kIndeterminate),
        timeout_seconds(timeout_seconds),
        num_failed_tests_before_stop(num_failed_tests_before_stop) {}

  static TestConfig FromCommandLine(
      const std::string& test_file, const std::string& test_data_file,
      const std::chrono::seconds& timeout_seconds,
      int num_failed_tests_before_stop,
      const std::vector<std::string>& commandline_args) {
    // Set num_failed_tests_before_stop to 0, means users want to run as many
    // as tests in one run.
    if (num_failed_tests_before_stop == 0) {
      num_failed_tests_before_stop = std::numeric_limits<int>::max();
    }

    TestConfig config{test_file, test_data_file, timeout_seconds,
                      num_failed_tests_before_stop};

    for (size_t i = 0; i < commandline_args.size(); i++) {
      if (commandline_args[i] == "--test-data-dir") {
        config.test_data_dir =
            GetParam(commandline_args, ++i, "--test-data-dir");
      } else if (commandline_args[i] == "--no-verbose") {
        config.verbose = false;
      } else if (commandline_args[i] == "--force-tty") {
        config.tty_mode = TriBool::kTrue;
      } else if (commandline_args[i] == "--no-tty") {
        config.tty_mode = TriBool::kFalse;
      } else if (commandline_args[i] == "--force-color") {
        config.color_mode = TriBool::kTrue;
      } else if (commandline_args[i] == "--no-color") {
        config.color_mode = TriBool::kFalse;
      } else if (commandline_args[i] == "--no-update-js") {
        config.update_js = false;
      } else if (commandline_args[i] == "--help" ||
                 commandline_args[i] == "-h") {
        PrintUsageAndExit();
      } else {
        throw std::runtime_error("CL: Unrecognized argument: " +
                                 commandline_args[i]);
      }
    }

    if (!config.test_data_dir.empty()) {
      if (!platform::IsDir(config.test_data_dir.c_str())) {
        throw std::runtime_error(
            FmtStr("CL: --test_data_dir argument ({}) is not a directory",
                   config.test_data_dir));
      }
    } else {
      config.test_data_dir = GetDefaultTestDataDirPath();
    }

    if (config.test_data_dir.back() != '/') {
      config.test_data_dir += '/';
    }

    return config;
  }

  std::string test_data_dir;
  std::string test_file;
  std::string test_data_file;
  bool verbose = true;
  bool analyze_complexity = false;
  TriBool tty_mode;
  TriBool color_mode;
  bool update_js = false;
  std::chrono::seconds timeout_seconds;
  int num_failed_tests_before_stop;
};
