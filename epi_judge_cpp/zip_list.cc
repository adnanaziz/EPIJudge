#include <memory>

#include "list_node.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> ZippingLinkedList(
    const shared_ptr<ListNode<int>>& L) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"L"};
  generic_test_main(argc, argv, param_names, "zip_list.tsv",
                    &ZippingLinkedList);
  return 0;
}
