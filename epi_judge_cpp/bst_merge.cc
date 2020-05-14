#include <memory>

#include "bst_prototype_shared_ptr.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<BstNode<int>> MergeTwoBSTs(shared_ptr<BstNode<int>> A,
                                      shared_ptr<BstNode<int>> B) {
  // TODO - you fill in here.
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "bst_merge.cc", "bst_merge.tsv", &MergeTwoBSTs,
                         DefaultComparator{}, param_names);
}
