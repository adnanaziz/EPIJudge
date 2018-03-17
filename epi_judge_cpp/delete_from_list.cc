#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::shared_ptr;

// Delete the node past this one. Assume node is not a tail.
void DeleteAfter(const shared_ptr<ListNode<int>>& node) {
  // Implement this placeholder.
  return;
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
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "head", "node_idx"};
  return GenericTestMain(args, timeout_seconds, "delete_from_list.tsv",
                         &DeleteFromListWrapper, DefaultComparator{},
                         param_names);
}
