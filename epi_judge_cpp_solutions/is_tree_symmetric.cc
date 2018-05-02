#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>>&,
                    const unique_ptr<BinaryTreeNode<int>>&);

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return tree == nullptr || CheckSymmetric(tree->left, tree->right);
}

bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>>& subtree_0,
                    const unique_ptr<BinaryTreeNode<int>>& subtree_1) {
  if (subtree_0 == nullptr && subtree_1 == nullptr) {
    return true;
  } else if (subtree_0 != nullptr && subtree_1 != nullptr) {
    return subtree_0->data == subtree_1->data &&
           CheckSymmetric(subtree_0->left, subtree_1->right) &&
           CheckSymmetric(subtree_0->right, subtree_1->left);
  }
  // One subtree is empty, and the other is not.
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
