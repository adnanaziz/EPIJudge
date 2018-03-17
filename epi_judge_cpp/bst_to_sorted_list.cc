#include <memory>
#include <vector>

#include "bst_prototype_shared_ptr.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::shared_ptr;

shared_ptr<BstNode<int>> BSTToDoublyLinkedList(
    const shared_ptr<BstNode<int>>& tree) {
  // Implement this placeholder.
  return nullptr;
}

std::vector<int> BSTToDoublyLinkedListWrapper(
    TimedExecutor& executor, const std::shared_ptr<BstNode<int>>& tree) {
  auto list = executor.Run([&] { return BSTToDoublyLinkedList(tree); });

  if (list->left) {
    throw TestFailure(
        "Function must return the head of the list. Left link must be null");
  }
  std::vector<int> v;
  while (list) {
    v.push_back(list->data);
    if (list->right && list->right->left != list) {
      throw TestFailure("List is ill-formed");
    }
    list = list->right;
  }
  return v;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree"};
  return GenericTestMain(args, timeout_seconds, "bst_to_sorted_list.tsv",
                         &BSTToDoublyLinkedListWrapper, DefaultComparator{},
                         param_names);
}
