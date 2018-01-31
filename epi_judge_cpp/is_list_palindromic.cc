#include "list_node.h"

bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> L) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"L"};
  generic_test_main(argc, argv, param_names, "is_list_palindromic.tsv",
                    &IsLinkedListAPalindrome);
  return 0;
}
