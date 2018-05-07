#include <memory>
#include "bst_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::unique_ptr;

bool PairIncludesAncestorAndDescendantOfM(
    const unique_ptr<BstNode<int>>& possible_anc_or_desc_0,
    const unique_ptr<BstNode<int>>& possible_anc_or_desc_1,
    const unique_ptr<BstNode<int>>& middle) {
  // TODO - you fill in here.
  return true;
}
bool PairIncludesAncestorAndDescendantOfMWrapper(
    TimedExecutor& executor, const unique_ptr<BstNode<int>>& tree,
    int possible_anc_or_desc_0, int possible_anc_or_desc_1, int middle) {
  auto& candidate0 = MustFindNode(tree, possible_anc_or_desc_0);
  auto& candidate1 = MustFindNode(tree, possible_anc_or_desc_1);
  auto& middle_node = MustFindNode(tree, middle);
  return executor.Run([&] {
    return PairIncludesAncestorAndDescendantOfM(candidate0, candidate1,
                                                middle_node);
  });
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree",
                                       "possible_anc_or_desc_0",
                                       "possible_anc_or_desc_1", "middle"};
  return GenericTestMain(args, "descendant_and_ancestor_in_bst.cc",
                         "descendant_and_ancestor_in_bst.tsv",
                         &PairIncludesAncestorAndDescendantOfMWrapper,
                         DefaultComparator{}, param_names);
}
