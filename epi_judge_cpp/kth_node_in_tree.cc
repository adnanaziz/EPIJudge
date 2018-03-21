#include <istream>
#include <memory>
#include <string>
#include <vector>

#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::unique_ptr;

template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  int size;
};

const BinaryTreeNode<int>* FindKthNodeBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree, int k) {
  // Implement this placeholder.
  return nullptr;
}

template <typename KeyT>
struct SerializationTraits<unique_ptr<BinaryTreeNode<KeyT>>> {
  using key_traits = SerializationTraits<KeyT>;
  using node_type = BinaryTreeNode<typename key_traits::serialization_type>;
  using serialization_type = unique_ptr<node_type>;

  static const char* Name() {
    static std::string s =
        std::string("binary_tree(") + key_traits::Name() + ")";
    return s.c_str();
  }

  static serialization_type Parse(const std::string& str) {
    auto v = SerializationTraits<std::vector<std::string>>::Parse(str);
    return buildTreeFromVector(v);
  }

  static serialization_type JsonParse(std::istream& in) {
    auto v = SerializationTraits<std::vector<std::string>>::JsonParse(in);
    return buildTreeFromVector(v);
  }

  static serialization_type buildTreeFromVector(
      const std::vector<std::string>& data) {
    if (data.empty()) throw std::runtime_error("Tree parser: missing data");

    std::vector<node_type*> nodes;

    for (auto& x : data) {
      nodes.emplace_back(x == "null" ? nullptr
                                     : new node_type{key_traits::Parse(x),
                                                     nullptr, nullptr, 0});
    }
    std::vector<node_type*> candidate_children(rbegin(nodes), rend(nodes));
    auto root = serialization_type(candidate_children.back());
    candidate_children.pop_back();

    for (const auto& node : nodes) {
      if (node) {
        if (!candidate_children.empty()) {
          node->left = serialization_type(candidate_children.back());
          candidate_children.pop_back();
        } else
          node->left = nullptr;
        if (!candidate_children.empty()) {
          node->right = serialization_type(candidate_children.back());
          candidate_children.pop_back();
        } else
          node->right = nullptr;
      }
    }
    initSize(root);
    return root;
  }

  static int initSize(const serialization_type& node) {
    if (!node) return 0;
    node->size = 1 + initSize(node->left) + initSize(node->right);
    return node->size;
  }

  static bool Equal(const serialization_type& a, const serialization_type& b) {
    return EqualBinaryTrees(a, b);
  }
};

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
  return GenericTestMain(args, "kth_node_in_tree.tsv",
                         &FindKthNodeBinaryTreeWrapper, DefaultComparator{},
                         param_names);
}
