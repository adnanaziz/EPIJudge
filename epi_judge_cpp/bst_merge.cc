#include <memory>

#include "bst_prototype_shared_ptr.h"

using std::shared_ptr;

shared_ptr<BstNode<int>> MergeTwoBSTs(shared_ptr<BstNode<int>> A,
                                      shared_ptr<BstNode<int>> B) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A", "B"};
  generic_test_main(argc, argv, param_names, "bst_merge.tsv", &MergeTwoBSTs);
  return 0;
}
