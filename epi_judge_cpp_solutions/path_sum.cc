#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::unique_ptr;

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
  if (tree == nullptr) {
    return false;
  } else if (tree->left == nullptr && tree->right == nullptr) {  // Leaf.
    return remaining_weight == tree->data;
  }
  // Non-leaf.
  return HasPathSum(tree->left, remaining_weight - tree->data) ||
         HasPathSum(tree->right, remaining_weight - tree->data);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "remaining_weight"};
  return GenericTestMain(args, "path_sum.cc", "path_sum.tsv", &HasPathSum,
                         DefaultComparator{}, param_names);
}
