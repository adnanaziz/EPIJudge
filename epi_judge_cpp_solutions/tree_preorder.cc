#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::pair;
using std::stack;
using std::vector;

vector<int> PreorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<int> result;

  stack<pair<const BinaryTreeNode<int>*, bool>> in_process;
  in_process.emplace(tree.get(), false);
  while (!empty(in_process)) {
    auto [node, node_processed] = in_process.top();
    in_process.pop();
    if (node) {
      if (node_processed) {
        result.emplace_back(node->data);
      } else {
        in_process.emplace(node->right.get(), false);
        in_process.emplace(node->left.get(), false);
        in_process.emplace(node, true);
      }
    }
  }
  return result;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"tree"};
  return GenericTestMain(args, "tree_preorder.cc", "tree_preorder.tsv", &PreorderTraversal,
                         DefaultComparator{}, param_names);
}
// clang-format on
