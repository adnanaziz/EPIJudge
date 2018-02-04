#include <memory>

#include "bst_prototype_shared_ptr.h"

using std::shared_ptr;

shared_ptr<BstNode<int>> MergeTwoBSTs(shared_ptr<BstNode<int>> A,
                                      shared_ptr<BstNode<int>> B) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  GenericTestMain(args, "bst_merge.tsv", &MergeTwoBSTs, DefaultComparator{},
                  param_names);
  return 0;
}
