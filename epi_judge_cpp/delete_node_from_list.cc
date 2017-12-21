#include "list_node.h"
#include "test_framework/test_timer.h"

// Assumes node_to_delete is not tail.
void DeletionFromList(const shared_ptr<ListNode<int>>& node_to_delete) {
  // Implement this placeholder.
  return;
}

shared_ptr<ListNode<int>> DeletionFromListWrapper(
    TestTimer& timer, const shared_ptr<ListNode<int>>& head, int i) {
  static int nr = 1;
  nr++;
  shared_ptr<ListNode<int>> selected_node = head;
  while (i-- > 0) {
    if (!selected_node || !selected_node->next)
      throw std::runtime_error("Node index is out of range");
    selected_node = selected_node->next;
  }
  timer.Start();
  DeletionFromList(selected_node);
  timer.Stop();
  return head;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "delete_node_from_list.tsv",
                    &DeletionFromListWrapper);
  return 0;
}
