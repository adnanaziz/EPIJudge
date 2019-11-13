#include <memory>

#include "bst_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::unique_ptr;

bool SearchTarget(const unique_ptr<BstNode<int>>&,
                  const unique_ptr<BstNode<int>>&);

bool PairIncludesAncestorAndDescendantOfM(
    const unique_ptr<BstNode<int>>& possible_anc_or_desc_0,
    const unique_ptr<BstNode<int>>& possible_anc_or_desc_1,
    const unique_ptr<BstNode<int>>& middle) {
  auto* search_0 = possible_anc_or_desc_0.get();
  auto* search_1 = possible_anc_or_desc_1.get();

  // Perform interleaved searching from possible_anc_or_desc_0 and
  // possible_anc_or_desc_1 for middle.
  while (search_0 != possible_anc_or_desc_1.get() && search_0 != middle.get() &&
         search_1 != possible_anc_or_desc_0.get() && search_1 != middle.get() &&
         (search_0 || search_1)) {
    if (search_0) {
      search_0 = search_0->data > middle->data ? search_0->left.get()
                                               : search_0->right.get();
    }
    if (search_1) {
      search_1 = search_1->data > middle->data ? search_1->left.get()
                                               : search_1->right.get();
    }
  }

  // If both searches were unsuccessful, or we got from
  // possible_anc_or_desc_0 to possible_anc_or_desc_1 without seeing middle,
  // or from possible_anc_or_desc_1 to possible_anc_or_desc_0 without seeing
  // middle, middle cannot lie between possible_anc_or_desc_0 and
  // possible_anc_or_desc_1.
  if ((search_0 != middle.get() && search_1 != middle.get()) ||
      search_0 == possible_anc_or_desc_1.get() ||
      search_1 == possible_anc_or_desc_0.get()) {
    return false;
  }

  // If we get here, we already know one of possible_anc_or_desc_0 or
  // possible_anc_or_desc_1 has a path to middle. Check if middle has a path
  // to possible_anc_or_desc_1 or to possible_anc_or_desc_0.
  return SearchTarget(middle, search_0 == middle.get()
                                  ? possible_anc_or_desc_1
                                  : possible_anc_or_desc_0);
}

bool SearchTarget(const unique_ptr<BstNode<int>>& from,
                  const unique_ptr<BstNode<int>>& target) {
  auto* iter = from.get();
  while (iter && iter != target.get()) {
    iter = iter->data > target->data ? iter->left.get() : iter->right.get();
  }
  return iter == target.get();
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

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"executor", "tree", "possible_anc_or_desc_0", "possible_anc_or_desc_1", "middle"};
  return GenericTestMain(args, "descendant_and_ancestor_in_bst.cc", "descendant_and_ancestor_in_bst.tsv", &PairIncludesAncestorAndDescendantOfMWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
