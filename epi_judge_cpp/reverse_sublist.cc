#include "list_node.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"L", "start", "finish"};
  generic_test_main(argc, argv, param_names, "reverse_sublist.tsv",
                    &ReverseSublist);
  return 0;
}
