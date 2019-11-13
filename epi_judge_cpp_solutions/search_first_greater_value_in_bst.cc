#include <memory>

#include "bst_node.h"
#include "test_framework/generic_test.h"

using std::unique_ptr;

BstNode<int>* FindFirstGreaterThanK(const unique_ptr<BstNode<int>>& tree,
                                    int k) {
  BstNode<int>*subtree = tree.get(), *first_so_far = nullptr;
  while (subtree) {
    if (subtree->data > k) {
      first_so_far = subtree;
      subtree = subtree->left.get();
    } else {  // Root and all keys in left subtree are <= k, so skip them.
      subtree = subtree->right.get();
    }
  }
  return first_so_far;
}

int FindFirstGreaterThanKWrapper(const unique_ptr<BstNode<int>>& tree, int k) {
  auto result = FindFirstGreaterThanK(tree, k);
  return result ? result->data : -1;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"tree", "k"};
  return GenericTestMain(args, "search_first_greater_value_in_bst.cc", "search_first_greater_value_in_bst.tsv", &FindFirstGreaterThanKWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
