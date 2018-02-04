#include <memory>

#include "binary_tree_node.h"

using std::unique_ptr;

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "remaining_weight"};
  GenericTestMain(args, "path_sum.tsv", &HasPathSum, DefaultComparator{},
                  param_names);
  return 0;
}
