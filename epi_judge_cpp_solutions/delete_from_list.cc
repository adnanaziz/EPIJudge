#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::shared_ptr;

// Delete the node past this one. Assume node is not a tail.
void DeleteAfter(const shared_ptr<ListNode<int>>& node) {
  node->next = node->next->next;
}

shared_ptr<ListNode<int>> DeleteFromListWrapper(
    TimedExecutor& executor, const shared_ptr<ListNode<int>>& head,
    int node_idx) {
  shared_ptr<ListNode<int>> selected_node = head;
  shared_ptr<ListNode<int>> prev;
  while (node_idx-- > 0) {
    if (!selected_node || !selected_node->next)
      throw std::runtime_error("Node index is out of range");
    prev = selected_node;
    selected_node = selected_node->next;
  }
  executor.Run([&] { DeleteAfter(prev); });
  return head;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "head", "node_idx"};
  return GenericTestMain(args, "delete_from_list.cc", "delete_from_list.tsv",
                         &DeleteFromListWrapper, DefaultComparator{},
                         param_names);
}
