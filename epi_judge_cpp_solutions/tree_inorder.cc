#include <memory>
#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::stack;
using std::unique_ptr;
using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<int> result;

  struct NodeAndState {
    const BinaryTreeNode<int>* node;
    bool left_subtree_traversed;
  };
  stack<NodeAndState> in_process(
      {{tree.get(), /*left_subtree_traversed=*/false}});
  while (!empty(in_process)) {
    auto [node, left_subtree_traversed] = in_process.top();
    in_process.pop();
    if (node) {
      if (left_subtree_traversed) {
        result.emplace_back(node->data);
      } else {
        in_process.push({node->right.get(), /*left_subtree_traversed=*/false});
        in_process.push({node, /*left_subtree_traversed=*/true});
        in_process.push({node->left.get(),
                         /*left_subtree_traversed=*/false});
      }
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
