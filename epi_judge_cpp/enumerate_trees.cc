#include <algorithm>
#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::vector;

unique_ptr<BinaryTreeNode<int>> Clone(unique_ptr<BinaryTreeNode<int>>& tree) {
    return tree ? std::make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0, Clone(tree->left), Clone(tree->right)}) : nullptr;
}

vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBinaryTrees(int num_nodes) {
    vector<unique_ptr<BinaryTreeNode<int>>> results;

    if (num_nodes == 0) {
        results.emplace_back(nullptr);
        return results;
    }

    for (int num_left_nodes = 0; num_left_nodes < num_nodes; num_left_nodes++) {
        int num_right_nodes = num_nodes - num_left_nodes - 1;

        auto& left_tree = GenerateAllBinaryTrees(num_left_nodes);
        auto& right_tree = GenerateAllBinaryTrees(num_right_nodes);

        for (auto& left : left_tree) {
            for (auto& right : right_tree) {
                results.emplace_back(std::make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0, Clone(left), Clone(right)}));
            }
        }
    }
    return results;
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
