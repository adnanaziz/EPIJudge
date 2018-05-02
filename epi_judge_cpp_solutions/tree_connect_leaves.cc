#include <memory>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::unique_ptr;
using std::vector;

void AddLeavesLeftToRight(const unique_ptr<BinaryTreeNode<int>>&,
                          vector<const unique_ptr<BinaryTreeNode<int>>*>*);

vector<const unique_ptr<BinaryTreeNode<int>>*> CreateListOfLeaves(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<const unique_ptr<BinaryTreeNode<int>>*> leaves;
  AddLeavesLeftToRight(tree, &leaves);
  return leaves;
}

void AddLeavesLeftToRight(
    const unique_ptr<BinaryTreeNode<int>>& tree,
    vector<const unique_ptr<BinaryTreeNode<int>>*>* leaves_ptr) {
  if (tree != nullptr) {
    if (tree->left == nullptr && tree->right == nullptr) {
      leaves_ptr->emplace_back(&tree);
    } else {
      AddLeavesLeftToRight(tree->left, leaves_ptr);
      AddLeavesLeftToRight(tree->right, leaves_ptr);
    }
  }
}

vector<int> CreateListOfLeavesWrapper(
    TimedExecutor& executor, const unique_ptr<BinaryTreeNode<int>>& tree) {
  auto result = executor.Run([&] { return CreateListOfLeaves(tree); });

  if (std::any_of(std::begin(result), std::end(result),
                  [](const unique_ptr<BinaryTreeNode<int>>*& x) {
                    return !x || !*x;
                  })) {
    throw TestFailure("Result list can't contain nullptr");
  }

  vector<int> extracted_result;
  for (const auto& x : result) {
    extracted_result.push_back(x->get()->data);
  }
  return extracted_result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree"};
  return GenericTestMain(args, "tree_connect_leaves.cc",
                         "tree_connect_leaves.tsv", &CreateListOfLeavesWrapper,
                         DefaultComparator{}, param_names);
}
