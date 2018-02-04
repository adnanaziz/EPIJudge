
#include "binary_tree_node.h"

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  GenericTestMain(args, "is_tree_balanced.tsv", &IsBalanced,
                  DefaultComparator{}, param_names);
  return 0;
}
