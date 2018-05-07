#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"

BinaryTreeNode<int>* FindSuccessor(
    const unique_ptr<BinaryTreeNode<int>>& node) {
  auto* iter = node.get();
  if (iter->right != nullptr) {
    // Successor is the leftmost element in node's right subtree.
    iter = iter->right.get();
    while (iter->left) {
      iter = iter->left.get();
    }
    return iter;
  }

  // Find the closest ancestor whose left subtree contains node.
  while (iter->parent != nullptr && iter->parent->right.get() == iter) {
    iter = iter->parent;
  }
  // A return value of nullptr means node does not have successor, i.e., it is
  // the rightmost node in the tree.
  return iter->parent;
}

int FindSuccessorWrapper(const unique_ptr<BinaryTreeNode<int>>& tree,
                         int node_idx) {
  auto result = FindSuccessor(MustFindNode(tree, node_idx));
  return result ? result->data : -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "node_idx"};
  return GenericTestMain(args, "successor_in_tree.cc", "successor_in_tree.tsv",
                         &FindSuccessorWrapper, DefaultComparator{},
                         param_names);
}
