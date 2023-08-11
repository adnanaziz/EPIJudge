#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  // TODO - you fill in here.
  int currentIndex = A.size() - 1, nextIndex = A.size() - 2;
  // performing plus 1
  A[currentIndex] += 1;

  // No carry need to be handled
  if(A[currentIndex] < 9) {
      return A;
  }

  // handle the ripple carry
  while(currentIndex > 0) {
      if(A[currentIndex] > 9) {
          A[nextIndex--] += 1;
          A[currentIndex--] = 0;
      } else {
          break;
      }
  }

  // insert the most significant bit if needed
  if(A[0] > 9) {
      auto it = A.emplace(A.begin(), 1);
      A[1] = 0;
  }
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
