
#include "list_node.h"

shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>>& L) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"L"};
  generic_test_main(argc, argv, param_names, "even_odd_list_merge.tsv",
                    &EvenOddMerge);
  return 0;
}
