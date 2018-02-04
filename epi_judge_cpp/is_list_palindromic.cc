#include "list_node.h"

bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> L) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  GenericTestMain(args, "is_list_palindromic.tsv", &IsLinkedListAPalindrome,
                  DefaultComparator{}, param_names);
  return 0;
}
