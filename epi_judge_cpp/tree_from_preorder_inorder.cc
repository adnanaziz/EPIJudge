#include <vector>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"

using std::vector;

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(
    const vector<int>& preorder, const vector<int>& inorder) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder", "inorder"};
  GenericTestMain(args, "tree_from_preorder_inorder.tsv",
                  &BinaryTreeFromPreorderInorder, DefaultComparator{},
                  param_names);
  return 0;
}
