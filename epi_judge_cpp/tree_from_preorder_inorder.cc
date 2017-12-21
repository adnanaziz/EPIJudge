#include <vector>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"

using std::vector;

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(
    const vector<int>& preorder, const vector<int>& inorder) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "tree_from_preorder_inorder.tsv",
                    &BinaryTreeFromPreorderInorder);
  return 0;
}
