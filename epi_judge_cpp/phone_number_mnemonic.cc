#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> PhoneMnemonic(const string& phone_number) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"phone_number"};
  GenericTestMain(args, "phone_number_mnemonic.tsv", &PhoneMnemonic,
                  &UnorderedComparator<std::vector<std::string>>, param_names);
  return 0;
}
