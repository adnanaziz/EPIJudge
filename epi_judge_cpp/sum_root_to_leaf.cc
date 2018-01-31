#include "binary_tree_node.h"

int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"tree"};
  generic_test_main(argc, argv, param_names, "sum_root_to_leaf.tsv",
                    &SumRootToLeaf);
  return 0;
}
