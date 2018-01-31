#include <memory>

#include "bst_node.h"

using std::unique_ptr;

BstNode<int>* FindFirstGreaterThanK(const unique_ptr<BstNode<int>>& tree,
                                    int k) {
  // Implement this placeholder.
  return nullptr;
}

int FindFirstGreaterThanKWrapper(const unique_ptr<BstNode<int>>& tree, int k) {
  auto result = FindFirstGreaterThanK(tree, k);
  return result ? result->data : -1;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"tree", "k"};
  generic_test_main(argc, argv, param_names,
                    "search_first_greater_value_in_bst.tsv",
                    &FindFirstGreaterThanKWrapper);
  return 0;
}
