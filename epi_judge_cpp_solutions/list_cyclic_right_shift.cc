#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> L,
                                                   int k) {
  if (L == nullptr) {
    return L;
  }

  // Computes the length of L and the tail.
  auto tail = L;
  int n = 1;
  while (tail->next) {
    ++n, tail = tail->next;
  }
  k %= n;
  if (k == 0) {
    return L;
  }

  tail->next = L;  // Makes a cycle by connecting the tail to the head.
  int steps_to_new_head = n - k;
  auto new_tail = tail;
  while (steps_to_new_head--) {
    new_tail = new_tail->next;
  }
  auto new_head = new_tail->next;
  new_tail->next = nullptr;
  return new_head;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  return GenericTestMain(
      args, "list_cyclic_right_shift.cc", "list_cyclic_right_shift.tsv",
      &CyclicallyRightShiftList, DefaultComparator{}, param_names);
}
