#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> AddTwoNumbers(shared_ptr<ListNode<int>> L1,
                                        shared_ptr<ListNode<int>> L2) {
  shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
  auto place_iter = dummy_head;
  int carry = 0;
  while (L1 || L2 || carry) {
    int val = carry + (L1 ? L1->data : 0) + (L2 ? L2->data : 0);
    L1 = L1 ? L1->next : nullptr;
    L2 = L2 ? L2->next : nullptr;
    place_iter->next = make_shared<ListNode<int>>(val % 10, nullptr);
    carry = val / 10, place_iter = place_iter->next;
  }
  return dummy_head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "int_as_list_add.cc", "int_as_list_add.tsv",
                         &AddTwoNumbers, DefaultComparator{}, param_names);
}
