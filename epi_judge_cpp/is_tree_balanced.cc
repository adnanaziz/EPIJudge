
#include "binary_tree_node.h"

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "is_tree_balanced.tsv", &IsBalanced);
  return 0;
}
