#include <memory>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
