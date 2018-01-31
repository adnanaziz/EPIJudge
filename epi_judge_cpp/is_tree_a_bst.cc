#include <memory>

#include "binary_tree_node.h"

using std::unique_ptr;

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"tree"};
  generic_test_main(argc, argv, param_names, "is_tree_a_bst.tsv",
                    &IsBinaryTreeBST);
  return 0;
}
