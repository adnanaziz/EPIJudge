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
                                            const shared_ptr<ListNode<int>>& l,
                                            int node_idx, int new_node_data) {
  auto node = l;
  while (node_idx > 1) {
    node = node->next;
    --node_idx;
  }
  auto new_node = make_shared<ListNode<int>>(new_node_data, nullptr);
  timer.Start();
  InsertAfter(node, new_node);
  timer.Stop();
  return l;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "l", "node_idx",
                                       "new_node_data"};
  GenericTestMain(args, "insert_in_list.tsv", &InsertListWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
