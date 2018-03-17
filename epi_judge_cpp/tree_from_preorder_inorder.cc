#include <vector>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"

using std::vector;

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(
    const vector<int>& preorder, const vector<int>& inorder) {
  // Implement this placeholder.
  return nullptr;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder", "inorder"};
  return GenericTestMain(
      args, timeout_seconds, "tree_from_preorder_inorder.tsv",
      &BinaryTreeFromPreorderInorder, DefaultComparator{}, param_names);
}
