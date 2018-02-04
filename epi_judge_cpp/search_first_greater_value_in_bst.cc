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

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "k"};
  GenericTestMain(args, "search_first_greater_value_in_bst.tsv",
                  &FindFirstGreaterThanKWrapper, DefaultComparator{},
                  param_names);
  return 0;
}
