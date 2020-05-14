#include "list_node.h"
#include "test_framework/generic_test.h"
#define main _main
#include "reverse_list.cc"
#undef main

bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> L) {
  // Finds the second half of L.
  shared_ptr<ListNode<int>> slow = L, fast = L;
  while (fast && fast->next) {
    fast = fast->next->next, slow = slow->next;
  }

  // Compares the first half and the reversed second half lists.
  auto first_half_iter = L, second_half_iter = ReverseList(slow);
  while (second_half_iter && first_half_iter) {
    if (second_half_iter->data != first_half_iter->data) {
      return false;
    }
    second_half_iter = second_half_iter->next;
    first_half_iter = first_half_iter->next;
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "is_list_palindromic.cc",
                         "is_list_palindromic.tsv", &IsLinkedListAPalindrome,
                         DefaultComparator{}, param_names);
}
