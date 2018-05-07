#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L, int key) {
  while (L && L->data != key) {
    L = L->next;
  }
  // If key was not present in the list, L will have become null.
  return L;
}

int SearchListWrapper(shared_ptr<ListNode<int>> L, int key) {
  auto result = SearchList(L, key);
  return result ? result->data : -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "key"};
  return GenericTestMain(args, "search_in_list.cc", "search_in_list.tsv",
                         &SearchListWrapper, DefaultComparator{}, param_names);
}
