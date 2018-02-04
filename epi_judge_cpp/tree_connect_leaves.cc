#include <memory>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::unique_ptr;
using std::vector;

vector<const unique_ptr<BinaryTreeNode<int>>*> CreateListOfLeaves(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return {};
}

vector<int> CreateListOfLeavesWrapper(
    TestTimer& timer, const unique_ptr<BinaryTreeNode<int>>& tree) {
  timer.Start();
  auto result = CreateListOfLeaves(tree);
  timer.Stop();
  if (std::any_of(std::begin(result), std::end(result),
                  [](const unique_ptr<BinaryTreeNode<int>>*& x) {
                    return !x || !*x;
                  })) {
    throw TestFailureException("Result list can't contain nullptr");
  }

  vector<int> extracted_result;
  for (const auto& x : result) {
    extracted_result.push_back(x->get()->data);
  }
  return extracted_result;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "tree"};
  GenericTestMain(args, "tree_connect_leaves.tsv", &CreateListOfLeavesWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
