// @library
#pragma once

enum class TriBool { FALSE, TRUE, INDETERMINATE };

bool GetTriBoolOrDefault(TriBool tb, bool default_value) {
  switch (tb) {
    case TriBool::FALSE:
      return false;
    case TriBool::TRUE:
      return true;
    case TriBool::INDETERMINATE:
    default:
      return default_value;
  }
}
