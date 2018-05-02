#include <limits>
#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::numeric_limits;
using std::unique_ptr;

bool AreKeysInRange(const unique_ptr<BinaryTreeNode<int>>&, int, int);

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return AreKeysInRange(tree, numeric_limits<int>::min(),
                        numeric_limits<int>::max());
}

bool AreKeysInRange(const unique_ptr<BinaryTreeNode<int>>& tree, int low_range,
                    int high_range) {
  if (tree == nullptr) {
    return true;
  } else if (tree->data < low_range || tree->data > high_range) {
    return false;
  }

  return AreKeysInRange(tree->left, low_range, tree->data) &&
         AreKeysInRange(tree->right, tree->data, high_range);
}

bool InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree,
                      BinaryTreeNode<int>** prev) {
  if (!tree) {
    return true;
  } else if (!InorderTraversal(tree->left, prev)) {
    return false;
  } else if (*prev && (*prev)->data > tree->data) {
    return false;
  }
  *prev = tree.get();
  return InorderTraversal(tree->right, prev);
}

bool IsBinaryTreeBSTAlternative(const unique_ptr<BinaryTreeNode<int>>& tree) {
  BinaryTreeNode<int>* prev = nullptr;
  return InorderTraversal(tree, &prev);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
