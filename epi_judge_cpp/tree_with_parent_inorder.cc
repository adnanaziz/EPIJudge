#include <vector>

#include "binary_tree_with_parent_prototype.h"

using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "tree_with_parent_inorder.tsv",
                    &InorderTraversal);
  return 0;
}
