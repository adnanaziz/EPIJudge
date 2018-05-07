#include <algorithm>
#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;

vector<string> GetValidIpAddress(const string& s) {
  // TODO - you fill in here.
  return {};
}
bool comp(vector<string> expected, vector<string> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "valid_ip_addresses.cc",
                         "valid_ip_addresses.tsv", &GetValidIpAddress, &comp,
                         param_names);
}
