#include <memory>

#include "bst_node.h"

using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder_sequence"};
  GenericTestMain(args, "bst_from_preorder.tsv", &RebuildBSTFromPreorder,
                  DefaultComparator{}, param_names);
  return 0;
}
