#include <memory>
#include <vector>

#include "binary_tree_node.h"

using std::unique_ptr;
using std::vector;

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"tree"};
  generic_test_main(argc, argv, param_names, "tree_level_order.tsv",
                    &BinaryTreeDepthOrder);
  return 0;
}
