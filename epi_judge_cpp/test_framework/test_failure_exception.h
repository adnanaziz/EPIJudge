// @library
#pragma once

#include <string>

/**
 * Tested function is allowed to throw this exception
 * in order to mark the current test as failed.
 */
class TestFailureException {
 public:
  explicit TestFailureException(std::string what) : what_(what) {}

  const std::string& what() const { return what_; }

 private:
  const std::string what_;
};
