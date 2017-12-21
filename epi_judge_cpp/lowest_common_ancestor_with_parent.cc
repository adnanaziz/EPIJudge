
#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& node_0,
                         const unique_ptr<BinaryTreeNode<int>>& node_1) {
  // Implement this placeholder.
  return nullptr;
}

int LcaWrapper(TestTimer& timer, const unique_ptr<BinaryTreeNode<int>>& root,
               int key1, int key2) {
  auto& node1 = MustFindNode(root, key1);
  auto& node2 = MustFindNode(root, key2);

  timer.Start();
  auto result = LCA(node1, node2);
  timer.Stop();

  if (!result) {
    throw TestFailureException("Result can not be nullptr");
  }
  return result->data;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "lowest_common_ancestor.tsv", &LcaWrapper);
  return 0;
}
