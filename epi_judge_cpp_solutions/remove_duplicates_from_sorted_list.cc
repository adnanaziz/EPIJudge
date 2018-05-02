#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> RemoveDuplicates(const shared_ptr<ListNode<int>>& L) {
  auto iter = L;
  while (iter) {
    // Uses next_distinct to find the next distinct value.
    auto next_distinct = iter->next;
    while (next_distinct && next_distinct->data == iter->data) {
      next_distinct = next_distinct->next;
    }
    iter->next = next_distinct;
    iter = next_distinct;
  }
  return L;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "remove_duplicates_from_sorted_list.cc",
                         "remove_duplicates_from_sorted_list.tsv",
                         &RemoveDuplicates, DefaultComparator{}, param_names);
}
