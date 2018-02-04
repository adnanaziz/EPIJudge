#include <memory>

#include "list_node.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> ZippingLinkedList(
    const shared_ptr<ListNode<int>>& L) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  GenericTestMain(args, "zip_list.tsv", &ZippingLinkedList, DefaultComparator{},
                  param_names);
  return 0;
}
