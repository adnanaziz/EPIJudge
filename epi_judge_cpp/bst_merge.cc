#include <memory>

#include "bst_prototype_shared_ptr.h"
#include "test_framework/generic_test.h"

using std::shared_ptr;

shared_ptr<BstNode<int>> MergeTwoBSTs(shared_ptr<BstNode<int>> A,
                                      shared_ptr<BstNode<int>> B) {
  // Implement this placeholder.
  return nullptr;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, timeout_seconds, "bst_merge.tsv", &MergeTwoBSTs,
                         DefaultComparator{}, param_names);
}
