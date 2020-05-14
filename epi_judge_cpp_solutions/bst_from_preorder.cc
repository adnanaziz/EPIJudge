#include <algorithm>
#include <memory>

#include "bst_node.h"
#include "test_framework/generic_test.h"

using std::find_if_not;
using std::make_unique;
using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> RebuildBSTFromPreorderHelper(const vector<int>&, int,
                                                      int);

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
  return RebuildBSTFromPreorderHelper(preorder_sequence, 0,
                                      size(preorder_sequence));
}

// Builds a BST from preorder_sequence[start, end - 1].
unique_ptr<BstNode<int>> RebuildBSTFromPreorderHelper(
    const vector<int>& preorder_sequence, int start, int end) {
  if (start >= end) {
    return nullptr;
  }

  int transition_point = distance(
      cbegin(preorder_sequence),
      find_if_not(cbegin(preorder_sequence) + start, cend(preorder_sequence),
                  [&](int a) { return a <= preorder_sequence[start]; }));
  return make_unique<BstNode<int>>(
      preorder_sequence[start],
      RebuildBSTFromPreorderHelper(preorder_sequence, start + 1,
                                   transition_point),
      RebuildBSTFromPreorderHelper(preorder_sequence, transition_point, end));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder_sequence"};
  return GenericTestMain(args, "bst_from_preorder.cc", "bst_from_preorder.tsv",
                         &RebuildBSTFromPreorder, DefaultComparator{},
                         param_names);
}
