#include <memory>
#include <stack>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::stack;
using std::unique_ptr;
using std::vector;

// We use stack and previous node pointer to simulate postorder traversal.
vector<int> PostorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  if (tree == nullptr) {  // Empty tree.
    return {};
  }

  stack<BinaryTreeNode<int>*> path;
  BinaryTreeNode<int>* prev = nullptr;
  path.emplace(tree.get());
  vector<int> postorder_sequence;
  while (!empty(path)) {
    auto curr = path.top();
    if (prev == nullptr || prev->left.get() == curr ||
        prev->right.get() == curr) {
      // We came down to curr from prev.
      if (curr->left != nullptr) {  // Traverse left.
        path.emplace(curr->left.get());
      } else if (curr->right != nullptr) {  // Traverse right.
        path.emplace(curr->right.get());
      } else {  // Leaf node, so visit current node.
        postorder_sequence.emplace_back(curr->data);
        path.pop();
      }
    } else if (curr->left.get() == prev) {
      // Done with left, so now traverse right.
      if (curr->right != nullptr) {
        path.emplace(curr->right.get());
      } else {  // No right child, so visit curr.
        postorder_sequence.emplace_back(curr->data);
        path.pop();
      }
    } else {
      // Finished traversing left and right, so visit curr.
      postorder_sequence.emplace_back(curr->data);
      path.pop();
    }
    prev = curr;
  }
  return postorder_sequence;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_postorder.cc", "tree_postorder.tsv",
                         &PostorderTraversal, DefaultComparator{}, param_names);
}
