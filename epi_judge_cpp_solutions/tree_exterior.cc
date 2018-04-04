#include <algorithm>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::vector;

void LeftBoundaryAndLeaves(const unique_ptr<BinaryTreeNode<int>>&, bool,
                           vector<const unique_ptr<BinaryTreeNode<int>>*>*);
void RightBoundaryAndLeaves(const unique_ptr<BinaryTreeNode<int>>&, bool,
                            vector<const unique_ptr<BinaryTreeNode<int>>*>*);
bool IsLeaf(const unique_ptr<BinaryTreeNode<int>>&);

vector<const unique_ptr<BinaryTreeNode<int>>*> ExteriorBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<const unique_ptr<BinaryTreeNode<int>>*> exterior;
  if (tree != nullptr) {
    exterior.emplace_back(&tree);
    LeftBoundaryAndLeaves(tree->left, true, &exterior);
    RightBoundaryAndLeaves(tree->right, true, &exterior);
  }
  return exterior;
}

// Computes the nodes from the root to the leftmost leaf followed by all the
// leaves in subtree.
void LeftBoundaryAndLeaves(
    const unique_ptr<BinaryTreeNode<int>>& subtree, bool is_boundary,
    vector<const unique_ptr<BinaryTreeNode<int>>*>* exterior_ptr) {
  if (subtree != nullptr) {
    if (is_boundary || IsLeaf(subtree)) {
      exterior_ptr->emplace_back(&subtree);
    }
    LeftBoundaryAndLeaves(subtree->left, is_boundary, exterior_ptr);
    LeftBoundaryAndLeaves(
        subtree->right, is_boundary && subtree->left == nullptr, exterior_ptr);
  }
}

// Computes the leaves in left-to-right order followed by the rightmost leaf
// to the root path in subtree.
void RightBoundaryAndLeaves(
    const unique_ptr<BinaryTreeNode<int>>& subtree, bool is_boundary,
    vector<const unique_ptr<BinaryTreeNode<int>>*>* exterior_ptr) {
  if (subtree != nullptr) {
    RightBoundaryAndLeaves(
        subtree->left, is_boundary && subtree->right == nullptr, exterior_ptr);
    RightBoundaryAndLeaves(subtree->right, is_boundary, exterior_ptr);
    if (is_boundary || IsLeaf(subtree)) {
      exterior_ptr->emplace_back(&subtree);
    }
  }
}

bool IsLeaf(const unique_ptr<BinaryTreeNode<int>>& node) {
  return node->left == nullptr && node->right == nullptr;
}

vector<int> CreateOutputVector(
    const vector<const unique_ptr<BinaryTreeNode<int>>*>& L) {
  if (std::find(std::begin(L), std::end(L), nullptr) != std::end(L)) {
    throw TestFailure("Resulting list contains nullptr");
  }
  std::vector<int> output;
  for (const auto* l : L) {
    output.push_back((*l)->data);
  }
  return output;
}

vector<int> ExteriorBinaryTreeWrapper(
    TimedExecutor& executor, const unique_ptr<BinaryTreeNode<int>>& tree) {
  auto result = executor.Run([&] { return ExteriorBinaryTree(tree); });

  return CreateOutputVector(result);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree"};
  return GenericTestMain(args, "tree_exterior.tsv", &ExteriorBinaryTreeWrapper,
                         DefaultComparator{}, param_names);
}
