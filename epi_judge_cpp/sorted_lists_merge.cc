#include "list_node.h"

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"L1", "L2"};
  generic_test_main(argc, argv, param_names, "sorted_lists_merge.tsv",
                    &MergeTwoSortedLists);
  return 0;
}
