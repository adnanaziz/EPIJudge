#include <memory>
#include <unordered_map>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"

using std::make_unique;
using std::unique_ptr;
using std::unordered_map;
using std::vector;

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorderHelper(
    const vector<int>&, int, int, int, int, const unordered_map<int, int>&);

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(
    const vector<int>& preorder, const vector<int>& inorder) {
  unordered_map<int, int> node_to_inorder_idx;
  for (int i = 0; i < size(inorder); ++i) {
    node_to_inorder_idx.emplace(inorder[i], i);
  }
  return BinaryTreeFromPreorderInorderHelper(
      preorder, /*preorder_start=*/0, size(preorder), /*inorder_start=*/0,
      size(inorder), node_to_inorder_idx);
}

// Builds the subtree with preorder[preorder_start, preorder_end - 1] and
// inorder[inorder_start, inorder_end - 1].
unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorderHelper(
    const vector<int>& preorder, int preorder_start, int preorder_end,
    int inorder_start, int inorder_end,
    const unordered_map<int, int>& node_to_inorder_idx) {
  if (preorder_end <= preorder_start || inorder_end <= inorder_start) {
    return nullptr;
  }
  size_t root_inorder_idx = node_to_inorder_idx.at(preorder[preorder_start]);
  size_t left_subtree_size = root_inorder_idx - inorder_start;

  return make_unique<BinaryTreeNode<int>>(
      preorder[preorder_start],
      // Recursively builds the left subtree.
      BinaryTreeFromPreorderInorderHelper(
          preorder, preorder_start + 1, preorder_start + 1 + left_subtree_size,
          inorder_start, root_inorder_idx, node_to_inorder_idx),
      // Recursively builds the right subtree.
      BinaryTreeFromPreorderInorderHelper(
          preorder, preorder_start + 1 + left_subtree_size, preorder_end,
          root_inorder_idx + 1, inorder_end, node_to_inorder_idx));
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"preorder", "inorder"};
  return GenericTestMain(args, "tree_from_preorder_inorder.cc", "tree_from_preorder_inorder.tsv", &BinaryTreeFromPreorderInorder,
                         DefaultComparator{}, param_names);
}
// clang-format on
