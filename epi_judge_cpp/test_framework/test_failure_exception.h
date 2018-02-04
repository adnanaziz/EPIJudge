// @library
#pragma once

#include <string>

/**
 * Tested function is allowed to throw this exception
 * in order to mark the current test as failed.
 */
class TestFailureException {
 public:
  explicit TestFailureException(std::string message)
      : message_(std::move(message)) {}

  const std::string& what() const { return message_; }

 private:
  const std::string message_;
};
