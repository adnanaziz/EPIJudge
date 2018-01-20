#include <memory>

#include "bst_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_timer.h"

using std::unique_ptr;

bool PairIncludesAncestorAndDescendantOfM(
    const unique_ptr<BstNode<int>>& possible_anc_or_desc_0,
    const unique_ptr<BstNode<int>>& possible_anc_or_desc_1,
    const unique_ptr<BstNode<int>>& middle) {
  // Implement this placeholder.
  return true;
}

bool PairIncludesAncestorAndDescendantOfMWrapper(
    TestTimer& timer, const unique_ptr<BstNode<int>>& tree, int candidate1idx,
    int candidate2idx, int middle_idx) {
  auto& candidate1 = MustFindNode(tree, candidate1idx);
  auto& candidate2 = MustFindNode(tree, candidate2idx);
  auto& middle = MustFindNode(tree, middle_idx);
  timer.Start();
  bool result =
      PairIncludesAncestorAndDescendantOfM(candidate1, candidate2, middle);
  timer.Stop();
  return result;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "descendant_and_ancestor_in_bst.tsv",
                    &PairIncludesAncestorAndDescendantOfMWrapper);
  return 0;
}
