
#pragma once

// MinGW defines TRUE and FALSE macros, that's why we use prefix here
enum class TriBool { kFalse, kTrue, kIndeterminate };

bool GetTriBoolOrDefault(TriBool tb, bool default_value) {
  switch (tb) {
    case TriBool::kFalse:
      return false;
    case TriBool::kTrue:
      return true;
    case TriBool::kIndeterminate:
    default:
      return default_value;
  }
}
