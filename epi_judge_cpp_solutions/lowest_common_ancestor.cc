#include <memory>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::unique_ptr;

struct Status;
Status LcaHelper(const unique_ptr<BinaryTreeNode<int>>&,
                 const unique_ptr<BinaryTreeNode<int>>&,
                 const unique_ptr<BinaryTreeNode<int>>&);

struct Status {
  int num_target_nodes;
  BinaryTreeNode<int>* ancestor;
};

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  return LcaHelper(tree, node0, node1).ancestor;
}

// Returns an object consisting of an int and a node. The int field is
// 0, 1, or 2 depending on how many of {node0, node1} are present in
// the tree. If both are present in the tree, when ancestor is
// assigned to a non-null value, it is the LCA.
Status LcaHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                 const unique_ptr<BinaryTreeNode<int>>& node0,
                 const unique_ptr<BinaryTreeNode<int>>& node1) {
  if (tree == nullptr) {
    return {/*num_target_nodes=*/0, /*ancestor=*/nullptr};
  }

  auto left_result = LcaHelper(tree->left, node0, node1);
  if (left_result.num_target_nodes == 2) {
    // Found both nodes in the left subtree.
    return left_result;
  }
  auto right_result = LcaHelper(tree->right, node0, node1);
  if (right_result.num_target_nodes == 2) {
    // Found both nodes in the right subtree.
    return right_result;
  }
  int num_target_nodes = left_result.num_target_nodes +
                         right_result.num_target_nodes + (tree == node0) +
                         (tree == node1);
  return {num_target_nodes, num_target_nodes == 2 ? tree.get() : nullptr};
}

int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(tree, node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
