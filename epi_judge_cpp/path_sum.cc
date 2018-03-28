#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::unique_ptr;

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
  // Implement this placeholder.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "remaining_weight"};
  return GenericTestMain(args, "path_sum.tsv", &HasPathSum, DefaultComparator{},
                         param_names);
}
