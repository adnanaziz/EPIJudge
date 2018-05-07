#include <memory>
#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::stack;
using std::unique_ptr;
using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  stack<const BinaryTreeNode<int>*> s;
  const auto* curr = tree.get();
  vector<int> result;

  while (!empty(s) || curr) {
    if (curr) {
      s.push(curr);
      // Going left.
      curr = curr->left.get();
    } else {
      // Going up.
      curr = s.top();
      s.pop();
      result.emplace_back(curr->data);
      // Going right.
      curr = curr->right.get();
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_inorder.cc", "tree_inorder.tsv",
                         &InorderTraversal, DefaultComparator{}, param_names);
}
