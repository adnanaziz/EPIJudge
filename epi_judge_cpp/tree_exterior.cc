#include <vector>

#include "binary_tree_node.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::vector;

vector<const unique_ptr<BinaryTreeNode<int>>*> ExteriorBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return {};
}

vector<int> CreateOutputVector(
    const vector<const unique_ptr<BinaryTreeNode<int>>*>& L) {
  if (std::find(std::begin(L), std::end(L), nullptr) != std::end(L)) {
    throw TestFailureException("Resulting list contains nullptr");
  }
  std::vector<int> output;
  for (const auto* l : L) {
    output.push_back((*l)->data);
  }
  return output;
}

vector<int> ExteriorBinaryTreeWrapper(
    TestTimer& timer, const unique_ptr<BinaryTreeNode<int>>& tree) {
  timer.Start();
  auto result = ExteriorBinaryTree(tree);
  timer.Stop();
  return CreateOutputVector(result);
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "tree_exterior.tsv",
                    &ExteriorBinaryTreeWrapper);
  return 0;
}
