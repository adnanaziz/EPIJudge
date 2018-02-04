#include <algorithm>
#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/test_timer.h"

using std::vector;

vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBinaryTrees(int num_nodes) {
  // Implement this placeholder.
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

vector<vector<int>> GenerateAllBinaryTreesWrapper(TestTimer& timer,
                                                  int num_nodes) {
  timer.Start();
  auto result = GenerateAllBinaryTrees(num_nodes);
  timer.Stop();

  vector<vector<int>> serialized;
  for (auto& x : result) {
    serialized.push_back(SerializeStructure(x));
  }
  std::sort(begin(serialized), end(serialized));
  return serialized;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "num_nodes"};
  GenericTestMain(args, "enumerate_trees.tsv", &GenerateAllBinaryTreesWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
