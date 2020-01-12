
#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> ReverseList(const shared_ptr<ListNode<int>>& head) {
  shared_ptr<ListNode<int>> prev = nullptr, curr = head;
  while (curr) {
    auto temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"head"};
  return GenericTestMain(args, "reverse_list.cc", "reverse_list.tsv",
                         &ReverseList, DefaultComparator{}, param_names);
}
