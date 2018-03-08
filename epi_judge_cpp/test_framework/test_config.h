// @library
#pragma once

#include <chrono>
#include <stdexcept>
#include <string>
#include <vector>

#include "platform.h"
#include "test_utils.h"
#include "tribool.h"

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
      "usage: <program name> [-h] [--test-data-dir [TEST_DATA_DIR]]\n"
      "                      [--no-stop-on-error] [--no-verbose]\n"
      "                      [--force-tty] [--no-tty] [--force-color] "
      "[--no-color]\n"
      "\n"
      "optional arguments:\n"
      "  -h, --help            show this help message and exit\n"
      "  --test-data-dir [TEST_DATA_DIR]\n"
      "                        path to test_data directory\n"
      "  --no-stop-on-error    continue execution even if one or several "
      "tests failed\n"
      "  --no-verbose          suppress failure description on test failure\n"
      "  --force-tty           enable tty features (like printing output on "
      "the same\n"
      "                        line) even in case stdout is not a tty "
      "device\n"
      "  --no-tty              never use tty features\n"
      "  --force-color         enable colored output even in case stdout is "
      "not a tty\n"
      "                        device\n"
      "  --no-color            never use colored output\n";
  std::cout << usage_string;
  exit(0);
}

struct TestConfig {
  TestConfig(const std::string& test_data_file,
             const std::chrono::milliseconds& timeout)
      : test_data_file(test_data_file),
        stop_on_error(true),
        verbose(true),
        tty_mode(TriBool::INDETERMINATE),
        color_mode(TriBool::INDETERMINATE),
        timeout(timeout) {}

  static TestConfig FromCommandLine(
      const std::string& test_data_file, const std::chrono::seconds& timeout,
      const std::vector<std::string>& commandline_args) {
    TestConfig config{test_data_file, timeout};

    for (size_t i = 0; i < commandline_args.size(); i++) {
      if (commandline_args[i] == "--test-data-dir") {
        config.test_data_dir =
            GetParam(commandline_args, ++i, "--test-data-dir");
      } else if (commandline_args[i] == "--no-stop-on-error") {
        config.stop_on_error = false;
      } else if (commandline_args[i] == "--no-verbose") {
        config.verbose = false;
      } else if (commandline_args[i] == "--force-tty") {
        config.tty_mode = TriBool::TRUE;
      } else if (commandline_args[i] == "--no-tty") {
        config.tty_mode = TriBool::FALSE;
      } else if (commandline_args[i] == "--force-color") {
        config.color_mode = TriBool::TRUE;
      } else if (commandline_args[i] == "--no-color") {
        config.color_mode = TriBool::FALSE;
      } else if (commandline_args[i] == "--help" ||
                 commandline_args[i] == "-h") {
        PrintUsageAndExit();
      } else {
        throw std::runtime_error("CL: Unrecognized argument: " +
                                 commandline_args[i]);
      }
    }

    if (!config.test_data_dir.empty()) {
      if (!platform::IsDir(config.test_data_dir.c_str()))
        throw std::runtime_error(
            FmtStr("CL: --test_data_dir argument ({}) is not a directory",
                   config.test_data_dir));
    } else {
      config.test_data_dir = GetDefaultTestDataDirPath();
    }

    if (config.test_data_dir.back() != '/') {
      config.test_data_dir += '/';
    }

    return config;
  }

  std::string test_data_dir;
  std::string test_data_file;
  bool stop_on_error;
  bool verbose;
  TriBool tty_mode;
  TriBool color_mode;
  std::chrono::milliseconds timeout;
};
