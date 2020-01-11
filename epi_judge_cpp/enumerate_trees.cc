#include <algorithm>
#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::vector;

vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBinaryTrees(int num_nodes) {
  // TODO - you fill in here.
  return {};
}
vector<int> SerializeStructure(const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<int> result;

  std::stack<BinaryTreeNode<int>*> stack;
  stack.push(tree.get());
  while (!stack.empty()) {
    auto p = stack.top();
    stack.pop();
    result.push_back(p != nullptr);
    if (p) {
      stack.push(p->left.get());
      stack.push(p->right.get());
    }
  }
  return result;
}

vector<vector<int>> GenerateAllBinaryTreesWrapper(TimedExecutor& executor,
                                                  int num_nodes) {
  auto result = executor.Run([&] { return GenerateAllBinaryTrees(num_nodes); });

  vector<vector<int>> serialized;
  for (auto& x : result) {
    serialized.push_back(SerializeStructure(x));
  }
  std::sort(begin(serialized), end(serialized));
  return serialized;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "num_nodes"};
  return GenericTestMain(args, "enumerate_trees.cc", "enumerate_trees.tsv",
                         &GenerateAllBinaryTreesWrapper, DefaultComparator{},
                         param_names);
}
