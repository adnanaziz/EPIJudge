
#pragma once

#include <algorithm>
#include <memory>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

#include "fmt_print_fwd.h"

template <typename Node, typename T>
void TreeGenerateHelper(const Node& tree, std::vector<T>* result, int order) {
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

//TODO Try type extractor pattern
template <template <typename...> class SmartPtr,
          template <typename...> class Node, typename T,
          typename... MsvcWorkaround>
std::vector<T> GeneratePreorder(const SmartPtr<Node<T>, MsvcWorkaround...>& tree) {
  std::vector<T> result;
  TreeGenerateHelper(tree, &result, -1);
  return result;
}

template <template <typename...> class SmartPtr,
          template <typename...> class Node, typename T,
          typename... MsvcWorkaround>
std::vector<T> GenerateInorder(const SmartPtr<Node<T>, MsvcWorkaround...>& tree) {
  std::vector<T> result;
  TreeGenerateHelper(tree, &result, 0);
  return result;
}

template <template <typename...> class SmartPtr,
          template <typename...> class Node, typename T,
          typename... MsvcWorkaround>
std::vector<T> GeneratePostorder(const SmartPtr<Node<T>, MsvcWorkaround...>& tree) {
  std::vector<T> result;
  TreeGenerateHelper(tree, &result, 1);
  return result;
}

template <typename Node, typename DataType>
const Node* FindNode(const Node* tree, DataType val) {
  if (*tree) {
    if ((*tree)->data == val) {
      return tree;
    }

    const auto& left_result = FindNode(&(*tree)->left, val);
    if (left_result) {
      return left_result;
    }

    const auto& right_result = FindNode(&(*tree)->right, val);
    if (right_result) {
      return right_result;
    }
  }

  return nullptr;
}

template <typename Node, typename Data>
Node& MustFindNode(Node& tree, Data& data) {
  auto result = FindNode(&tree, data);
  if (!result) {
    throw std::runtime_error(std::to_string(data) +
                             " was not found in the tree");
  }
  return *result;
};

template <typename Node1, typename Node2>
bool EqualBinaryTrees(const Node1& node1, const Node2& node2) {
  if (node1 && node2) {
    return node1->data == node2->data &&
           EqualBinaryTrees(node1->left, node2->left) &&
           EqualBinaryTrees(node1->right, node2->right);
  } else {
    return !node1 && !node2;
  }
}

template <typename Node>
std::string BinaryTreeToString(const Node& tree) {
  std::stringstream result;
  std::queue<const Node*> q;
  std::unordered_set<const Node*> visited;
  bool first = true;
  int null_nodes_pending = 0;

  result << "[";
  q.push(&tree);

  while (!q.empty()) {
    const Node* node = q.front();
    q.pop();
    if (visited.count(node)) {
      throw std::runtime_error("Detected a cycle in the tree");
    }
    if (*node) {
      if (first) {
        first = false;
      } else {
        result << ", ";
      }

      while (null_nodes_pending) {
        result << "null, ";
        null_nodes_pending--;
      }

      result << '"';
      PrintTo(result, (*node)->data);
      result << '"';

      visited.emplace(node);
      q.push(&(*node)->left);
      q.push(&(*node)->right);
    } else {
      null_nodes_pending++;
    }
  }

  result << "]";
  return result.str();
}

template <typename Node>
int BinaryTreeHeight(const Node& tree) {
  if (!tree) {
    return -1;
  }
  return 1 + std::max(BinaryTreeHeight(tree->left),
                      BinaryTreeHeight(tree->right));
}

template <typename Node>
int BinaryTreeSize(const Node& tree) {
  if (!tree) {
    return 0;
  }
  return 1 + BinaryTreeSize(tree->left) + BinaryTreeSize(tree->right);
}

// C++ framework specific functions

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
