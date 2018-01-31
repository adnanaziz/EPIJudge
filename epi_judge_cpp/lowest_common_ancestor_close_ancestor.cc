#include <memory>

#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::unique_ptr;

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  // Implement this placeholder.
  return nullptr;
}

int LcaWrapper(TestTimer& timer, const unique_ptr<BinaryTreeNode<int>>& tree,
               int node0, int node1) {
  timer.Start();
  auto result = LCA(MustFindNode(tree, node0), MustFindNode(tree, node1));
  timer.Stop();

  if (!result) {
    throw TestFailureException("Result can not be nullptr");
  }
  return result->data;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "tree", "node0", "node1"};
  generic_test_main(argc, argv, param_names, "lowest_common_ancestor.tsv",
                    &LcaWrapper);
  return 0;
}
