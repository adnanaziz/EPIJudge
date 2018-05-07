#include <iterator>
#include <memory>
#include <vector>
#include "doubly_list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::make_shared;
using std::vector;

// Returns the root of the corresponding BST. The prev and next fields of the
// list nodes are used as the BST nodes left and right fields, respectively.
// The length of the list is given.
shared_ptr<ListNode<int>> BuildBSTFromSortedDoublyList(
    shared_ptr<ListNode<int>> l, int length) {
  // TODO - you fill in here.
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
    throw TestFailure("Too few values in the tree");
  }
  if (*current != tree->data) {
    throw TestFailure("Unexpected value");
  }
  ++current;

  CompareVectorAndTree(tree->next, current, end);
}

void BuildBSTFromSortedDoublyListWrapper(TimedExecutor& executor,
                                         const vector<int>& l) {
  shared_ptr<ListNode<int>> input_list;
  for (auto it = rbegin(l); it != rend(l); ++it) {
    input_list = make_shared<ListNode<int>>(*it, nullptr, input_list);
    if (input_list->next) {
      input_list->next->prev = input_list;
    }
  }

  input_list = executor.Run([&] {
    return BuildBSTFromSortedDoublyList(input_list, static_cast<int>(l.size()));
  });

  auto current = begin(l);
  CompareVectorAndTree(input_list, current, end(l));
  if (current != end(l)) {
    throw TestFailure("Too many values in the tree");
  }

  while (input_list) {
    input_list->prev.reset();
    input_list = input_list->next;
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "l"};
  return GenericTestMain(
      args, "sorted_list_to_bst.cc", "sorted_list_to_bst.tsv",
      &BuildBSTFromSortedDoublyListWrapper, DefaultComparator{}, param_names);
}
