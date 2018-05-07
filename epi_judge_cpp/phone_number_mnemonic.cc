#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;
vector<string> PhoneMnemonic(const string& phone_number) {
  // TODO - you fill in here.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"phone_number"};
  return GenericTestMain(args, "phone_number_mnemonic.cc",
                         "phone_number_mnemonic.tsv", &PhoneMnemonic,
                         &UnorderedComparator<std::vector<std::string>>,
                         param_names);
}
