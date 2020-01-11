#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
#define main _main
#include "sorted_lists_merge.cc"
#undef main

shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> L) {
  // Base cases: L is empty or a single node, nothing to do.
  if (L == nullptr || L->next == nullptr) {
    return L;
  }

  // Find the midpoint of L using a slow and a fast pointer.
  shared_ptr<ListNode<int>> pre_slow = nullptr, slow = L, fast = L;
  while (fast && fast->next) {
    pre_slow = slow;
    fast = fast->next->next, slow = slow->next;
  }

  if (pre_slow) {
    pre_slow->next = nullptr;  // Splits the list into two equal-sized lists.
  }
  return MergeTwoSortedLists(StableSortList(L), StableSortList(slow));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "sort_list.cc", "sort_list.tsv", &StableSortList,
                         DefaultComparator{}, param_names);
}
