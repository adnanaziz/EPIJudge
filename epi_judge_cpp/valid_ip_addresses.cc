#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> GetValidIpAddress(const string& s) {
  // Implement this placeholder.
  return {};
}

bool comp(vector<string> expected, vector<string> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  GenericTestMain(args, "valid_ip_addresses.tsv", &GetValidIpAddress, &comp,
                  param_names);
  return 0;
}
