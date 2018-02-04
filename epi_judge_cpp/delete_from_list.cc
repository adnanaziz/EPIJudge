#include <memory>

#include "list_node.h"
#include "test_framework/test_timer.h"

using std::shared_ptr;

// Delete the node past this one. Assume node is not a tail.
void DeleteAfter(const shared_ptr<ListNode<int>>& node) {
  // Implement this placeholder.
  return;
}

shared_ptr<ListNode<int>> DeleteFromListWrapper(
    TestTimer& timer, const shared_ptr<ListNode<int>>& head, int node_idx) {
  shared_ptr<ListNode<int>> selected_node = head;
  shared_ptr<ListNode<int>> prev;
  while (node_idx-- > 0) {
    if (!selected_node || !selected_node->next)
      throw std::runtime_error("Node index is out of range");
    prev = selected_node;
    selected_node = selected_node->next;
  }
  timer.Start();
  DeleteAfter(prev);
  timer.Stop();
  return head;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "head", "node_idx"};
  GenericTestMain(args, "delete_from_list.tsv", &DeleteFromListWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
