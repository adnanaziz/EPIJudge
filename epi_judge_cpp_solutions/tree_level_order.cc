#include <memory>
#include <queue>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::queue;
using std::unique_ptr;
using std::vector;

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<vector<int>> result;
  if (!tree.get()) {
    return result;
  }

  queue<BinaryTreeNode<int>*> curr_depth_nodes({tree.get()});
  while (!empty(curr_depth_nodes)) {
    queue<BinaryTreeNode<int>*> next_depth_nodes;
    vector<int> this_level;
    while (!empty(curr_depth_nodes)) {
      auto curr = curr_depth_nodes.front();
      curr_depth_nodes.pop();
      this_level.emplace_back(curr->data);

      if (curr->left) {
        next_depth_nodes.emplace(curr->left.get());
      }
      if (curr->right) {
        next_depth_nodes.emplace(curr->right.get());
      }
    }

    result.emplace_back(this_level);
    curr_depth_nodes = next_depth_nodes;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_level_order.cc", "tree_level_order.tsv",
                         &BinaryTreeDepthOrder, DefaultComparator{},
                         param_names);
}
