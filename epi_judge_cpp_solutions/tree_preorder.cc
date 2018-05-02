#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::stack;
using std::vector;

vector<int> PreorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  stack<BinaryTreeNode<int>*> path;
  path.emplace(tree.get());
  vector<int> result;
  while (!empty(path)) {
    auto curr = path.top();
    path.pop();
    if (curr != nullptr) {
      result.emplace_back(curr->data);
      path.emplace(curr->right.get());
      path.emplace(curr->left.get());
    }
  }
  return result;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"tree"};
  return GenericTestMain(args, "tree_preorder.cc", "tree_preorder.tsv", &PreorderTraversal, DefaultComparator{}, param_names);
}
// clang-format on
