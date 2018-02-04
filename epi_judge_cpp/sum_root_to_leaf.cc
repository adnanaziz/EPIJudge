#include "binary_tree_node.h"

int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  GenericTestMain(args, "sum_root_to_leaf.tsv", &SumRootToLeaf,
                  DefaultComparator{}, param_names);
  return 0;
}
