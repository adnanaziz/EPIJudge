#include <memory>
#include <string>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::make_unique;
using std::string;
using std::unique_ptr;
using std::vector;

unique_ptr<BinaryTreeNode<int>> ReconstructPreorderHelper(const vector<int*>&,
                                                          int*);

unique_ptr<BinaryTreeNode<int>> ReconstructPreorder(
    const vector<int*>& preorder) {
  int subtree_idx_pointer = 0;
  return ReconstructPreorderHelper(preorder, &subtree_idx_pointer);
}

// Reconstructs the subtree that is rooted at subtreeIdx.
unique_ptr<BinaryTreeNode<int>> ReconstructPreorderHelper(
    const vector<int*>& preorder, int* subtree_idx_pointer) {
  int& subtree_idx = *subtree_idx_pointer;
  int* subtree_key = preorder[subtree_idx];
  ++subtree_idx;
  if (subtree_key == nullptr) {
    return nullptr;
  }
  // Note that ReconstructPreorderHelper updates subtree_idx. So the order of
  // following two calls are critical.
  auto left_subtree = ReconstructPreorderHelper(preorder, subtree_idx_pointer);
  auto right_subtree = ReconstructPreorderHelper(preorder, subtree_idx_pointer);
  return make_unique<BinaryTreeNode<int>>(*subtree_key, move(left_subtree),
                                          move(right_subtree));
}

unique_ptr<BinaryTreeNode<int>> ReconstructPreorderWrapper(
    TimedExecutor& executor, const vector<string>& preorder) {
  vector<int> values;
  vector<int*> ptrs;
  values.reserve(preorder.size());
  for (auto& s : preorder) {
    if (s == "null") {
      ptrs.push_back(nullptr);
    } else {
      int i = std::stoi(s);
      values.push_back(i);
      ptrs.push_back(&values.back());
    }
  }

  return executor.Run([&] { return ReconstructPreorder(ptrs); });
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"executor", "preorder"};
  return GenericTestMain(args, "tree_from_preorder_with_null.cc", "tree_from_preorder_with_null.tsv", &ReconstructPreorderWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
