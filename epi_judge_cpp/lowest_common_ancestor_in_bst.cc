#include <memory>

#include "bst_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::unique_ptr;

// Input nodes are nonempty and the key at s is less than or equal to that at
// b.
BstNode<int>* FindLCA(const unique_ptr<BstNode<int>>& tree,
                      const unique_ptr<BstNode<int>>& s,
                      const unique_ptr<BstNode<int>>& b) {
  // Implement this placeholder.
  return nullptr;
}

int LcaWrapper(TestTimer& timer, const std::unique_ptr<BstNode<int>>& tree,
               int s, int b) {
  timer.Start();
  auto result = FindLCA(tree, MustFindNode(tree, s), MustFindNode(tree, b));
  timer.Stop();
  if (!result) {
    throw TestFailureException("Result can not be nullptr");
  }
  return result->data;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "tree", "s", "b"};
  generic_test_main(argc, argv, param_names,
                    "lowest_common_ancestor_in_bst.tsv", &LcaWrapper);
  return 0;
}
