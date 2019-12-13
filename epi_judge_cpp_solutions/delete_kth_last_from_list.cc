#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"

using std::shared_ptr;

// Assumes L has at least k nodes, deletes the k-th last node in L.
shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& L,
                                        int k) {
  auto dummy_head = make_shared<ListNode<int>>(0, L);
  auto first = dummy_head->next;
  while (k--) {
    first = first->next;
  }

  auto second = dummy_head;
  while (first) {
    second = second->next, first = first->next;
  }
  // second points to the (k + 1)-th last node, deletes its successor.
  second->next = second->next->next;
  return dummy_head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  return GenericTestMain(args, "delete_kth_last_from_list.cc",
                         "delete_kth_last_from_list.tsv", &RemoveKthLast,
                         DefaultComparator{}, param_names);
}
