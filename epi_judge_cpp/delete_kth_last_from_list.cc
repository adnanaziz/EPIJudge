#include <memory>

#include "list_node.h"

using std::shared_ptr;

// Assumes L has at least k nodes, deletes the k-th last node in L.
shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& L,
                                        int k) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  GenericTestMain(args, "delete_kth_last_from_list.tsv", &RemoveKthLast,
                  DefaultComparator{}, param_names);
  return 0;
}
