#include <memory>
#include <queue>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/timed_executor.h"

using std::queue;
using std::unique_ptr;
using test_framework::BinaryTreeSerializationTrait;

template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  BinaryTreeNode<T>* next = nullptr;  // Populates this field.

  explicit BinaryTreeNode(T data) : data(data){};
};

void PopulateLowerLevelNextField(BinaryTreeNode<int>*);

void ConstructRightSibling(BinaryTreeNode<int>* tree) {
  while (tree && tree->left) {
    PopulateLowerLevelNextField(tree);
    tree = tree->left.get();
  }
}

void PopulateLowerLevelNextField(BinaryTreeNode<int>* start_node) {
  while (start_node) {
    // Populate left child's next field.
    start_node->left->next = start_node->right.get();
    // Populate right child's next field if start_node is not the last node of
    // this level.
    if (start_node->next) {
      start_node->right->next = start_node->next->left.get();
    }
    start_node = start_node->next;
  }
}

namespace test_framework {
template <>
struct SerializationTrait<unique_ptr<BinaryTreeNode<int>>>
    : BinaryTreeSerializationTrait<unique_ptr<BinaryTreeNode<int>>, false> {};
}  // namespace test_framework

std::vector<std::vector<int>> ConstructRightSiblingWrapper(
    TimedExecutor& executor, unique_ptr<BinaryTreeNode<int>>& tree) {
  executor.Run([&] { ConstructRightSibling(tree.get()); });

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

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"executor", "tree"};
  return GenericTestMain(args, "tree_right_sibling.cc", "tree_right_sibling.tsv", &ConstructRightSiblingWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
