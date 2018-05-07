#include <istream>
#include <memory>
#include <string>
#include <vector>
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
using std::unique_ptr;
template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  int size;
};

const BinaryTreeNode<int>* FindKthNodeBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree, int k) {
  // TODO - you fill in here.
  return nullptr;
}
template <typename KeyT>
struct SerializationTraits<std::unique_ptr<BinaryTreeNode<KeyT>>>
    : BinaryTreeSerializationTraits<std::unique_ptr<BinaryTreeNode<KeyT>>,
                                    false> {
  using serialization_type = std::unique_ptr<BinaryTreeNode<KeyT>>;
  using base =
      BinaryTreeSerializationTraits<std::unique_ptr<BinaryTreeNode<KeyT>>,
                                    false>;
  static serialization_type Parse(const std::string& str) {
    auto tree = base::Parse(str);
    InitSize(tree);
    return std::move(tree);
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    auto tree = base::JsonParse(json_object);
    InitSize(tree);
    return std::move(tree);
  }

 private:
  static int InitSize(const serialization_type& node) {
    if (!node) return 0;
    node->size = 1 + InitSize(node->left) + InitSize(node->right);
    return node->size;
  }
};

namespace detail {
template <typename KeyT>
struct IsBinaryTreeImpl<std::unique_ptr<BinaryTreeNode<KeyT>>>
    : std::true_type {};
}  // namespace detail

int FindKthNodeBinaryTreeWrapper(const unique_ptr<BinaryTreeNode<int>>& tree,
                                 int k) {
  auto result = FindKthNodeBinaryTree(tree, k);
  if (!result) {
    throw TestFailure("Result can't be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "k"};
  return GenericTestMain(args, "kth_node_in_tree.cc", "kth_node_in_tree.tsv",
                         &FindKthNodeBinaryTreeWrapper, DefaultComparator{},
                         param_names);
}
