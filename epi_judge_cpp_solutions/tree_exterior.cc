#include <algorithm>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::vector;

void LeftBoundary(const unique_ptr<BinaryTreeNode<int>>&,
                  vector<const unique_ptr<BinaryTreeNode<int>>*>*);
void RightBoundary(const unique_ptr<BinaryTreeNode<int>>&,
                   vector<const unique_ptr<BinaryTreeNode<int>>*>*);
void Leaves(const unique_ptr<BinaryTreeNode<int>>&,
            vector<const unique_ptr<BinaryTreeNode<int>>*>*);

vector<const unique_ptr<BinaryTreeNode<int>>*> ExteriorBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  if (tree == nullptr) {
    return {};
  }

  vector<const unique_ptr<BinaryTreeNode<int>>*> exterior{&tree};
  LeftBoundary(tree->left, &exterior);
  Leaves(tree->left, &exterior);
  Leaves(tree->right, &exterior);
  RightBoundary(tree->right, &exterior);
  return exterior;
}

// Computes the nodes from the root to the leftmost leaf.
void LeftBoundary(
    const unique_ptr<BinaryTreeNode<int>>& subtree,
    vector<const unique_ptr<BinaryTreeNode<int>>*>* exterior_ptr) {
  if (subtree == nullptr ||
      (subtree->left == nullptr && subtree->right == nullptr)) {
    return;
  }
  exterior_ptr->emplace_back(&subtree);
  if (subtree->left != nullptr) {
    LeftBoundary(subtree->left, exterior_ptr);
  } else {
    LeftBoundary(subtree->right, exterior_ptr);
  }
}

// Computes the nodes from the rightmost leaf to the root.
void RightBoundary(
    const unique_ptr<BinaryTreeNode<int>>& subtree,
    vector<const unique_ptr<BinaryTreeNode<int>>*>* exterior_ptr) {
  if (subtree == nullptr ||
      (subtree->left == nullptr && subtree->right == nullptr)) {
    return;
  }
  if (subtree->right != nullptr) {
    RightBoundary(subtree->right, exterior_ptr);
  } else {
    RightBoundary(subtree->left, exterior_ptr);
  }
  exterior_ptr->emplace_back(&subtree);
}

// Compute the leaves in left-to-right order.
void Leaves(const unique_ptr<BinaryTreeNode<int>>& subtree,
            vector<const unique_ptr<BinaryTreeNode<int>>*>* exterior_ptr) {
  if (subtree == nullptr) {
    return;
  }
  if (subtree->left == nullptr && subtree->right == nullptr) {
    exterior_ptr->emplace_back(&subtree);
    return;
  }
  Leaves(subtree->left, exterior_ptr);
  Leaves(subtree->right, exterior_ptr);
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
  return GenericTestMain(args, "tree_exterior.cc", "tree_exterior.tsv",
                         &ExteriorBinaryTreeWrapper, DefaultComparator{},
                         param_names);
}
