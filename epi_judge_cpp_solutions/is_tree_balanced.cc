#include <algorithm>
#include <cstdlib>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::abs;
using std::max;

struct BalancedStatusWithHeight;
BalancedStatusWithHeight CheckBalanced(const unique_ptr<BinaryTreeNode<int>>&);

struct BalancedStatusWithHeight {
  bool balanced;
  int height;
};

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return CheckBalanced(tree).balanced;
}

// First value of the return value indicates if tree is balanced, and if
// balanced the second value of the return value is the height of tree.
BalancedStatusWithHeight CheckBalanced(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  if (tree == nullptr) {
    return {/*balanced=*/true, /*height=*/-1};
  }

  auto left_result = CheckBalanced(tree->left);
  if (!left_result.balanced) {
    return left_result;
  }
  auto right_result = CheckBalanced(tree->right);
  if (!right_result.balanced) {
    return right_result;
  }

  bool is_balanced = abs(left_result.height - right_result.height) <= 1;
  int height = max(left_result.height, right_result.height) + 1;
  return {is_balanced, height};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
