#include <memory>
#include "bst_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
  // TODO - you fill in here.
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder_sequence"};
  return GenericTestMain(args, "bst_from_preorder.cc", "bst_from_preorder.tsv",
                         &RebuildBSTFromPreorder, DefaultComparator{},
                         param_names);
}
