#include <algorithm>
#include <cstdlib>

#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::swap;

int GetDepth(const BinaryTreeNode<int>*);

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  BinaryTreeNode<int>*iter0 = node0.get(), *iter1 = node1.get();
  int depth0 = GetDepth(iter0), depth1 = GetDepth(iter1);
  // Makes iter0 as the deeper node in order to simplify the code.
  if (depth1 > depth0) {
    swap(iter0, iter1);
  }
  // Ascends from the deeper node.
  int depth_diff = abs(depth0 - depth1);
  while (depth_diff--) {
    iter0 = iter0->parent;
  }

  // Now ascends both nodes until we reach the LCA.
  while (iter0 != iter1) {
    iter0 = iter0->parent, iter1 = iter1->parent;
  }
  return iter0;
}

int GetDepth(const BinaryTreeNode<int>* node) {
  int depth = 0;
  while (node->parent) {
    ++depth, node = node->parent;
  }
  return depth;
}

int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
