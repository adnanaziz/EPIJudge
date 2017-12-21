#include <memory>

#include "list_node.h"
#include "test_framework/test_timer.h"

using std::make_shared;
using std::shared_ptr;

// Insert new_node after node.
void InsertAfter(const shared_ptr<ListNode<int>>& node,
                 const shared_ptr<ListNode<int>>& new_node) {
  // Implement this placeholder.
  return;
}

shared_ptr<ListNode<int>> InsertListWrapper(TestTimer& timer,
                                            const shared_ptr<ListNode<int>>& L,
                                            int pos, int key) {
  auto node = L;
  while (pos > 1) {
    node = node->next;
    --pos;
  }
  auto new_node = make_shared<ListNode<int>>(key, nullptr);
  timer.Start();
  InsertAfter(node, new_node);
  timer.Stop();
  return L;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "insert_in_list.tsv", &InsertListWrapper);
  return 0;
}
