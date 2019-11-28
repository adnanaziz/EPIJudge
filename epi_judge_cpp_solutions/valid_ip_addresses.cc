#include <algorithm>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::stoi;
using std::string;
using std::vector;

bool IsValidPart(const string& s);

vector<string> GetValidIpAddress(const string& s) {
  vector<string> result;
  for (size_t i = 1; i < 4 && i < size(s); ++i) {
    if (const string first = s.substr(0, i); IsValidPart(first)) {
      for (size_t j = 1; i + j < size(s) && j < 4; ++j) {
        const string second = s.substr(i, j);
        if (IsValidPart(second)) {
          for (size_t k = 1; i + j + k < size(s) && k < 4; ++k) {
            const string third = s.substr(i + j, k),
                         fourth = s.substr(i + j + k);
            if (IsValidPart(third) && IsValidPart(fourth)) {
              result.emplace_back(first + "." + second + "." + third + "." +
                                  fourth);
            }
          }
        }
      }
    }
  }
  return result;
}

bool IsValidPart(const string& s) {
  if (size(s) > 3) {
    return false;
  }
  // "00", "000", "01", etc. are not valid, but "0" is valid.
  if (s.front() == '0' && size(s) > 1) {
    return false;
  }
  int val = stoi(s);
  return val <= 255 && val >= 0;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"s"};
  return GenericTestMain(args, "valid_ip_addresses.cc", "valid_ip_addresses.tsv", &GetValidIpAddress,
                         UnorderedComparator{}, param_names);
}
// clang-format on
