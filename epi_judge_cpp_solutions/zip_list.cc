#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
#define main _main
#include "reverse_list.cc"
#undef main

using std::shared_ptr;

shared_ptr<ListNode<int>> ZippingLinkedList(
    const shared_ptr<ListNode<int>>& L) {
  if (!L || !L->next) {
    return L;
  }

  // Finds the second half of L.
  auto slow = L, fast = L;
  while (fast && fast->next) {
    fast = fast->next->next, slow = slow->next;
  }

  auto first_half_head = L, second_half_head = slow->next;
  slow->next = nullptr;  // Splits the list into two lists.

  second_half_head = ReverseList(second_half_head);

  // Interleave the first half and the reversed of the second half.
  auto first_half_iter = first_half_head, second_half_iter = second_half_head;
  while (second_half_iter) {
    auto temp = second_half_iter->next;
    second_half_iter->next = first_half_iter->next;
    first_half_iter->next = second_half_iter;
    first_half_iter = first_half_iter->next->next;
    second_half_iter = temp;
  }
  return first_half_head;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "zip_list.cc", "zip_list.tsv",
                         &ZippingLinkedList, DefaultComparator{}, param_names);
}
