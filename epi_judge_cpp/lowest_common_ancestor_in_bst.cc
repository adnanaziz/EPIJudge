#include <memory>

#include "bst_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::unique_ptr;

// Input nodes are nonempty and the key at s is less than or equal to that at
// b.
BSTNode<int>* FindLCA(const unique_ptr<BSTNode<int>>& tree,
                      const unique_ptr<BSTNode<int>>& s,
                      const unique_ptr<BSTNode<int>>& b) {
  // Implement this placeholder.
  return nullptr;
}

int LcaWrapper(TestTimer& timer, const std::unique_ptr<BSTNode<int>>& root,
               int key1, int key2) {
  auto& node1 = MustFindNode(root, key1);
  auto& node2 = MustFindNode(root, key2);
  timer.Start();
  auto result = FindLCA(root, node1, node2);
  timer.Stop();
  if (!result) {
    throw TestFailureException("Result can not be nullptr");
  }
  return result->data;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "lowest_common_ancestor_in_bst.tsv",
                    &LcaWrapper);
  return 0;
}
