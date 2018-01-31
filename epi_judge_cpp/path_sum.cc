#include <memory>

#include "binary_tree_node.h"

using std::unique_ptr;

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"tree", "remaining_weight"};
  generic_test_main(argc, argv, param_names, "path_sum.tsv", &HasPathSum);
  return 0;
}
