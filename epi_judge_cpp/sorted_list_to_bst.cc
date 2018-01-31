#include <iterator>
#include <memory>
#include <vector>

#include "doubly_list_node.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::make_shared;
using std::vector;

// Returns the root of the corresponding BST. The prev and next fields of the
// list nodes are used as the BST nodes left and right fields, respectively.
// The length of the list is given.
shared_ptr<ListNode<int>> BuildBSTFromSortedDoublyList(
    shared_ptr<ListNode<int>> L, int length) {
  // Implement this placeholder.
  return nullptr;
}

void CompareVectorAndTree(const shared_ptr<ListNode<int>>& tree,
                          vector<int>::const_iterator& current,
                          const vector<int>::const_iterator& end) {
  if (!tree) {
    return;
  }

  CompareVectorAndTree(tree->prev, current, end);

  if (current == end) {
    throw TestFailureException("Too few values in the tree");
  }
  if (*current != tree->data) {
    throw TestFailureException("Unexpected value");
  }
  ++current;

  CompareVectorAndTree(tree->next, current, end);
}

void BuildBSTFromSortedDoublyListWrapper(TestTimer& timer,
                                         const vector<int>& L) {
  shared_ptr<ListNode<int>> list;
  for (auto it = rbegin(L); it != rend(L); ++it) {
    list = make_shared<ListNode<int>>(*it, nullptr, list);
    if (list->next) {
      list->next->prev = list;
    }
  }

  timer.Start();
  list = BuildBSTFromSortedDoublyList(list, static_cast<int>(L.size()));
  timer.Stop();

  auto current = begin(L);
  CompareVectorAndTree(list, current, end(L));
  if (current != end(L)) {
    throw TestFailureException("Too many values in the tree");
  }

  while (list) {
    list->prev.reset();
    list = list->next;
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "L"};
  generic_test_main(argc, argv, param_names, "sorted_list_to_bst.tsv",
                    &BuildBSTFromSortedDoublyListWrapper);
  return 0;
}
