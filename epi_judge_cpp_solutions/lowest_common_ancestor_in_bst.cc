#include <memory>

#include "bst_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::unique_ptr;

// Input nodes are nonempty and the key at s is less than or equal to that at
// b.
BstNode<int>* FindLca(const unique_ptr<BstNode<int>>& tree,
                      const unique_ptr<BstNode<int>>& s,
                      const unique_ptr<BstNode<int>>& b) {
  auto* p = tree.get();
  while (p->data < s->data || p->data > b->data) {
    // Keep searching since p is outside of [s, b].
    while (p->data < s->data) {
      p = p->right.get();  // LCA must be in p's right child.
    }
    while (p->data > b->data) {
      p = p->left.get();  // LCA must be in p's left child.
    }
  }
  // Now, s->data <= p->data && p->data <= b->data.
  return p;
}

int LcaWrapper(TimedExecutor& executor,
               const std::unique_ptr<BstNode<int>>& tree, int key0, int key1) {
  const unique_ptr<BstNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BstNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return FindLca(tree, node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_in_bst.cc",
                         "lowest_common_ancestor_in_bst.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
