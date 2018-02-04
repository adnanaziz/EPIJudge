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
    TestTimer& timer, const unique_ptr<BstNode<int>>& tree,
    int possible_anc_or_desc_0, int possible_anc_or_desc_1, int middle) {
  auto& candidate0 = MustFindNode(tree, possible_anc_or_desc_0);
  auto& candidate1 = MustFindNode(tree, possible_anc_or_desc_1);
  auto& middle_node = MustFindNode(tree, middle);
  timer.Start();
  bool result =
      PairIncludesAncestorAndDescendantOfM(candidate0, candidate1, middle_node);
  timer.Stop();
  return result;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "tree",
                                       "possible_anc_or_desc_0",
                                       "possible_anc_or_desc_1", "middle"};
  GenericTestMain(args, "descendant_and_ancestor_in_bst.tsv",
                  &PairIncludesAncestorAndDescendantOfMWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
