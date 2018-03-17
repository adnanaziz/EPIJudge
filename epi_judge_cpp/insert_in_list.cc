#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::make_shared;
using std::shared_ptr;

// Insert new_node after node.
void InsertAfter(const shared_ptr<ListNode<int>>& node,
                 const shared_ptr<ListNode<int>>& new_node) {
  // Implement this placeholder.
  return;
}

shared_ptr<ListNode<int>> InsertListWrapper(TimedExecutor& executor,
                                            const shared_ptr<ListNode<int>>& l,
                                            int node_idx, int new_node_data) {
  auto node = l;
  while (node_idx > 1) {
    node = node->next;
    --node_idx;
  }
  auto new_node = make_shared<ListNode<int>>(new_node_data, nullptr);

  executor.Run([&] { InsertAfter(node, new_node); });

  return l;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "l", "node_idx",
                                       "new_node_data"};
  return GenericTestMain(args, timeout_seconds, "insert_in_list.tsv",
                         &InsertListWrapper, DefaultComparator{}, param_names);
}
