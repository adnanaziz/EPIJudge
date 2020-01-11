#include <memory>
#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::pair;
using std::stack;
using std::unique_ptr;
using std::vector;

vector<int> PostorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<int> result;

  stack<pair<const BinaryTreeNode<int>*, bool>> in_process;
  in_process.emplace(tree.get(), false);
  while (!empty(in_process)) {
    auto [node, subtrees_traversed] = in_process.top();
    in_process.pop();
    if (node) {
      if (subtrees_traversed) {
        result.emplace_back(node->data);
      } else {
        in_process.emplace(node, true);
        in_process.emplace(node->right.get(), false);
        in_process.emplace(node->left.get(), false);
      }
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_postorder.cc", "tree_postorder.tsv",
                         &PostorderTraversal, DefaultComparator{}, param_names);
}
