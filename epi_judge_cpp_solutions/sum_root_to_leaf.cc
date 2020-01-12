#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

int SumRootToLeafHelper(const unique_ptr<BinaryTreeNode<int>>&, int);

int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return SumRootToLeafHelper(tree, /*partial_path_sum=*/0);
}

int SumRootToLeafHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                        int partial_path_sum) {
  if (tree == nullptr) {
    return 0;
  }

  partial_path_sum = partial_path_sum * 2 + tree->data;
  if (tree->left == nullptr && tree->right == nullptr) {  // Leaf.
    return partial_path_sum;
  }
  // Non-leaf.
  return SumRootToLeafHelper(tree->left, partial_path_sum) +
         SumRootToLeafHelper(tree->right, partial_path_sum);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "sum_root_to_leaf.cc", "sum_root_to_leaf.tsv",
                         &SumRootToLeaf, DefaultComparator{}, param_names);
}
