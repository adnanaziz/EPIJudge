#include <array>
#include <memory>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::array;
using std::make_unique;
using std::string;
using std::vector;

void PhoneMnemonicHelper(const string&, int, string*, vector<string>*);

vector<string> PhoneMnemonic(const string& phone_number) {
  vector<string> mnemonics;
  PhoneMnemonicHelper(phone_number, 0,
                      make_unique<string>(size(phone_number), 0).get(),
                      &mnemonics);
  return mnemonics;
}

const int kNumTelDigits = 10;

// The mapping from digit to corresponding characters.
const array<string, kNumTelDigits> kMapping = {
    {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}};

void PhoneMnemonicHelper(const string& phone_number, int digit,
                         string* partial_mnemonic, vector<string>* mnemonics) {
  if (digit == size(phone_number)) {
    // All digits are processed, so add partial_mnemonic to mnemonics.
    // (We add a copy since subsequent calls modify partial_mnemonic.)
    mnemonics->emplace_back(*partial_mnemonic);
  } else {
    // Try all possible characters for this digit.
    for (char c : kMapping[phone_number[digit] - '0']) {
      (*partial_mnemonic)[digit] = c;
      PhoneMnemonicHelper(phone_number, digit + 1, partial_mnemonic, mnemonics);
    }
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"phone_number"};
  return GenericTestMain(args, "phone_number_mnemonic.cc", "phone_number_mnemonic.tsv", &PhoneMnemonic,
                         UnorderedComparator{}, param_names);
}
// clang-format on
