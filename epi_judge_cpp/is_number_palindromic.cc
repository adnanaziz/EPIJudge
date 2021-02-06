#include "test_framework/generic_test.h"
bool IsPalindromeNumber(int x) {
  // TODO - you fill in here.
  //0 - Check if number is negative
  if(x <= 0) {
    return x == 0;
  }
  //1. Count the number if digit
  int num_of_digit = static_cast<int>(floor(log10(x))) + 1;
  //2. Create a mask
  int mask = static_cast<int>(pow(10, num_of_digit - 1));
  //3. Check as palindram by checking first and last digit
  for(int i = 0; i < num_of_digit / 2; i++){
    if(x/mask != x%10){
      return false;
    }
    x %= mask;
    x /= 10;
    mask/=100;

  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
