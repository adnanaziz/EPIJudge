
#pragma once

#include <numeric>
#include <string>

#include "any.h"

enum class PropertyName {
  EXCEPTION_MESSAGE,  // message of unhandled exception
  EXPLANATION,        // explanation from TSV file
  COMMAND,   // last command, that caused the error, in API-testing programs
  STATE,     // state of the user-defined collection (for instance, in API
             // testing)
  EXPECTED,  // expected result
  RESULT,    // user-produced result
  MISSING_ITEMS,   // list of items from input that are missing in the result
                   // set
  EXCESS_ITEMS,    // list of items from result that are missing in the input
                   // set
  MISMATCH_INDEX,  // for collections: index of the wrong item in result
                   // for binary trees: instance of TreePath describing the
                   // position of the wrong item
  EXPECTED_ITEM,   // value of the expected item in collection (not the whole
                   // collection)
  RESULT_ITEM      // value of the result item in collection (not the whole
  // collection)
};

class Property {
 public:
  Property(PropertyName name, const any::Any& value)
      : name_(name), value_(value) {}

  const std::string& Name() const {
    static std::string enum_strings[] = {
        "exception message", "explanation",   "command",       "state",
        "expected",          "result",        "missing items", "excess items",
        "mismatch index",    "expected item", "result item"};
    return enum_strings[Id()];
  }

  int Id() const { return static_cast<int>(name_); }

  any::Any& Value() { return value_; }

 private:
  PropertyName name_;
  any::Any value_;
};

/**
 * Tested function may throw this exception
 * in order to mark the current test as failed.
 */
class TestFailure {
 public:
  explicit TestFailure(std::string description = {})
      : description_(std::move(description)) {}

  TestFailure& WithProperty(PropertyName name, any::Any value) {
    properties_.emplace_back(name, std::move(value));
    return *this;
  }

  TestFailure& WithMismatchInfo(any::Any mismatch_index, any::Any expected_item,
                                any::Any result_item) {
    return WithProperty(PropertyName::MISMATCH_INDEX,
                        std::move(mismatch_index))
        .WithProperty(PropertyName::EXPECTED_ITEM, std::move(expected_item))
        .WithProperty(PropertyName::RESULT_ITEM, std::move(result_item));
  }

  const std::string& GetDescription() const { return description_; }

  const std::string& what() const { return GetDescription(); }

  size_t GetMaxPropertyNameLength() const {
    size_t max = 0;
    for (auto& x : properties_) {
      if (x.Name().size() > max) {
        max = x.Name().size();
      }
    }
    return max;
  }

  const std::vector<Property>& GetProperties() {
    std::sort(
        properties_.begin(), properties_.end(),
        [](const Property& a, const Property& b) { return a.Id() < b.Id(); });
    return properties_;
  }

 private:
  std::vector<Property> properties_;
  std::string description_;
};
