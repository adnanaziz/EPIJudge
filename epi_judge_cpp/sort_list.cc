#include <memory>

#include "list_node.h"

shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> L) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"L"};
  generic_test_main(argc, argv, param_names, "sort_list.tsv", &StableSortList);
  return 0;
}
