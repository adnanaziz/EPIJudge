#include <memory>
#include <vector>

#include "test_framework/test_timer.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::unique_ptr;

template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  BinaryTreeNode<T>* next;  // Populates this field.

  explicit BinaryTreeNode(T data) : data(data), next(nullptr){};
};

void ConstructRightSibling(BinaryTreeNode<int>* tree) {
  // Implement this placeholder.
  return;
}

template <>
struct SerializationTraits<unique_ptr<BinaryTreeNode<int>>>
    : BinaryTreeSerializationTraits<unique_ptr<BinaryTreeNode<int>>, false> {};

std::vector<std::vector<int>> ConstructRightSiblingWrapper(
    TestTimer& timer, unique_ptr<BinaryTreeNode<int>>& tree) {
  timer.Start();
  ConstructRightSibling(tree.get());
  timer.Stop();
  std::vector<std::vector<int>> result;
  auto level_start = tree.get();
  while (level_start) {
    result.emplace_back();
    auto level_iter = level_start;
    while (level_iter) {
      result.back().push_back(level_iter->data);
      level_iter = level_iter->next;
    }
    level_start = level_start->left.get();
  }

  return result;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "tree"};
  GenericTestMain(args, "tree_right_sibling.tsv", &ConstructRightSiblingWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
