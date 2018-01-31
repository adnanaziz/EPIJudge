#include <memory>

#include "bst_node.h"

using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"preorder_sequence"};
  generic_test_main(argc, argv, param_names, "bst_from_preorder.tsv",
                    &RebuildBSTFromPreorder);
  return 0;
}
