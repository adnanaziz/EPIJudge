#include <memory>
#include <vector>

#include "bst_prototype_shared_ptr.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::shared_ptr;

shared_ptr<BstNode<int>> BSTToDoublyLinkedList(
    const shared_ptr<BstNode<int>>& tree) {
  // Implement this placeholder.
  return nullptr;
}

std::vector<int> BSTToDoublyLinkedListWrapper(
    TestTimer& timer, const std::shared_ptr<BstNode<int>>& tree) {
  timer.Start();
  auto list = BSTToDoublyLinkedList(tree);
  timer.Stop();
  if (list->left) {
    throw TestFailureException(
        "Function must return the head of the list. Left link must be null");
  }
  std::vector<int> v;
  while (list) {
    v.push_back(list->data);
    if (list->right && list->right->left != list) {
      throw TestFailureException("List is ill-formed");
    }
    list = list->right;
  }
  return v;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "tree"};
  generic_test_main(argc, argv, param_names, "bst_to_sorted_list.tsv",
                    &BSTToDoublyLinkedListWrapper);
  return 0;
}
