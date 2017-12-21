#include <memory>

#include "bst_prototype_shared_ptr.h"

using std::shared_ptr;

shared_ptr<BSTNode<int>> MergeTwoBSTs(shared_ptr<BSTNode<int>> A,
                                      shared_ptr<BSTNode<int>> B) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "bst_merge.tsv", &MergeTwoBSTs);
  return 0;
}
