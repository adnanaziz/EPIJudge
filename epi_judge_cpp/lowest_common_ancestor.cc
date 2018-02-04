#include <memory>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::unique_ptr;

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  // Implement this placeholder.
  return nullptr;
}

int LcaWrapper(TestTimer& timer, const unique_ptr<BinaryTreeNode<int>>& tree,
               int node0, int node1) {
  timer.Start();
  auto result = LCA(tree, MustFindNode(tree, node0), MustFindNode(tree, node1));
  timer.Stop();

  if (!result) {
    throw TestFailureException("Result can not be nullptr");
  }
  return result->data;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "tree", "node0", "node1"};
  GenericTestMain(args, "lowest_common_ancestor.tsv", &LcaWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
