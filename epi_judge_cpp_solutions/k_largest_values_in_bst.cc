#include <memory>
#include <vector>

#include "bst_node.h"
#include "test_framework/generic_test.h"

using std::unique_ptr;
using std::vector;

void FindKLargestInBSTHelper(const unique_ptr<BstNode<int>>&, int,
                             vector<int>*);

vector<int> FindKLargestInBST(const unique_ptr<BstNode<int>>& tree, int k) {
  vector<int> k_largest_elements;
  FindKLargestInBSTHelper(tree, k, &k_largest_elements);
  return k_largest_elements;
}

void FindKLargestInBSTHelper(const unique_ptr<BstNode<int>>& tree, int k,
                             vector<int>* k_largest_elements) {
  // Perform reverse inorder traversal.
  if (tree && size(*k_largest_elements) < k) {
    FindKLargestInBSTHelper(tree->right, k, k_largest_elements);
    if (size(*k_largest_elements) < k) {
      k_largest_elements->emplace_back(tree->data);
      FindKLargestInBSTHelper(tree->left, k, k_largest_elements);
    }
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"tree", "k"};
  return GenericTestMain(args, "k_largest_values_in_bst.cc", "k_largest_values_in_bst.tsv", &FindKLargestInBST,
                         UnorderedComparator{}, param_names);
}
// clang-format on
