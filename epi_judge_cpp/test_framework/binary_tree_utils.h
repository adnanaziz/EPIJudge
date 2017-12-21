// @library
#pragma once

#include <memory>
#include <stdexcept>
#include <vector>

using std::vector;

namespace {

template <typename Node, typename T>
void TreeGenerateHelper(const Node& tree, vector<T>* result, int order) {
  if (tree) {
    if (order == -1) {
      result->emplace_back(tree->data);
    }
    TreeGenerateHelper(tree->left, result, order);
    if (order == 0) {
      result->emplace_back(tree->data);
    }
    TreeGenerateHelper(tree->right, result, order);
    if (order == 1) {
      result->emplace_back(tree->data);
    }
  }
}

template <typename Node, typename DataType>
const Node& FindNode(const Node& tree, DataType val) {
  if (tree && tree->data == val) {
    return tree;
  }
  if (tree && tree->left) {
    const auto& left_result = FindNode(tree->left, val);
    if (left_result->data == val) {
      return left_result;
    }
  }
  if (tree && tree->right) {
    const auto& right_result = FindNode(tree->right, val);
    if (right_result->data == val) {
      return right_result;
    }
  }
  return tree;
}

}  // namespace

template <template <typename...> class SmartPtr,
          template <typename...> class Node, typename T>
vector<T> GeneratePreorder(const SmartPtr<Node<T>>& tree) {
  vector<T> result;
  TreeGenerateHelper(tree, &result, -1);
  return result;
}

template <template <typename...> class SmartPtr,
          template <typename...> class Node, typename T>
vector<T> GenerateInorder(const SmartPtr<Node<T>>& tree) {
  vector<T> result;
  TreeGenerateHelper(tree, &result, 0);
  return result;
}

template <template <typename...> class SmartPtr,
          template <typename...> class Node, typename T>
vector<T> GeneratePostorder(const SmartPtr<Node<T>>& tree) {
  vector<T> result;
  TreeGenerateHelper(tree, &result, 1);
  return result;
}

template <typename Node1, typename Node2>
bool EqualBinaryTrees(const Node1& r1, const Node2& r2) {
  if (r1 && r2) {
    return EqualBinaryTrees(r1->left, r2->left) &&
           EqualBinaryTrees(r1->right, r2->right) && r1->data == r2->data;
  } else
    return !r1 && !r2;
}

template <typename Node, typename Data>
Node& MustFindNode(Node& tree, Data& data) {
  Node& result = FindNode(tree, data);
  if (!result || result->data != data) {
    throw std::runtime_error("Searched node is not found");
  }
  return result;
};

template <typename Node>
void DeleteBinaryTree(Node* tree) {
  if (tree && *tree) {
    if ((*tree)->left.get()) {
      DeleteBinaryTree(&((*tree)->left));
    }
    if ((*tree)->right.get()) {
      DeleteBinaryTree(&((*tree)->right));
    }
    tree->reset(nullptr);
  }
}
