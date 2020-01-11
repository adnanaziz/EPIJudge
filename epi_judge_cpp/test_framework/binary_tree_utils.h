
#pragma once

#include <algorithm>
#include <memory>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

#include "fmt_print_fwd.h"
#include "test_utils_meta.h"

namespace test_framework {
template <typename NodePtr>
decltype(auto) GeneratePreorder(const NodePtr& tree) {
  using node_t = template_param_by_index_t<NodePtr, 0>;
  using key_t = template_param_by_index_t<NodePtr, 0, 0>;
  std::vector<key_t> result;
  std::stack<const node_t*> s{{GetRawPtr(tree)}};

  while (!s.empty()) {
    auto node = s.top();
    s.pop();
    if (!node) {
      continue;
    }

    result.push_back(node->data);
    s.push(GetRawPtr(node->right));
    s.push(GetRawPtr(node->left));
  }

  return result;
}

template <typename NodePtr>
decltype(auto) GenerateInorder(const NodePtr& tree) {
  using node_t = template_param_by_index_t<NodePtr, 0>;
  using key_t = template_param_by_index_t<NodePtr, 0, 0>;
  std::vector<key_t> result;
  std::stack<const node_t*> s{{GetRawPtr(tree)}};
  bool initial = true;

  if (!tree) {
    return result;
  }

  while (!s.empty()) {
    auto node = s.top();
    s.pop();

    if (initial) {
      initial = false;
    } else {
      result.push_back(node->data);
      node = GetRawPtr(node->right);
    }

    while (node) {
      s.push(node);
      node = GetRawPtr(node->left);
    }
  }

  return result;
}

template <typename NodePtr>
decltype(auto) GeneratePostorder(const NodePtr& tree) {
  using node_t = template_param_by_index_t<NodePtr, 0>;
  using key_t = template_param_by_index_t<NodePtr, 0, 0>;
  std::vector<key_t> result;
  std::stack<const node_t*> s{{&tree}};

  while (!s.empty()) {
    auto node = s.top();
    s.pop();
    if (!node) {
      continue;
    }

    result.push_back(node->data);
    s.push(GetRawPtr(node->left));
    s.push(GetRawPtr(node->right));
  }

  std::reverse(result.begin(), result.end());

  return result;
}

template <typename NodePtr, typename Key>
const NodePtr* FindNode(const NodePtr* tree, Key& val) {
  std::stack<const NodePtr*> s{{tree}};

  while (!s.empty()) {
    auto node = s.top();
    s.pop();

    if (!*node) {
      continue;
    }

    if ((*node)->data == val) {
      return node;
    }

    s.push(&((*node)->left));
    s.push(&((*node)->right));
  }

  return nullptr;
}

template <typename NodePtr, typename Key>
NodePtr& MustFindNode(NodePtr& tree, Key& data) {
  auto result = FindNode(&tree, data);
  if (!result) {
    throw std::runtime_error(FmtStr("{} was not found in the tree", data));
  }
  return *result;
};

template <typename NodePtr1, typename NodePtr2>
bool EqualBinaryTrees(const NodePtr1& tree1, const NodePtr2& tree2) {
  using node1_t = template_param_by_index_t<NodePtr1, 0>;
  using node2_t = template_param_by_index_t<NodePtr2, 0>;
  std::stack<std::pair<const node1_t*, const node2_t*>> s{
      {{GetRawPtr(tree1), GetRawPtr(tree2)}}};

  while (!s.empty()) {
    auto nodes = s.top();
    s.pop();

    if ((nodes.first == nullptr) != (nodes.second == nullptr)) {
      return false;
    }

    if (nodes.first != nullptr) {
      if (nodes.first->data != nodes.second->data) {
        return false;
      }
      s.push({GetRawPtr(nodes.first->left), GetRawPtr(nodes.second->left)});
      s.push({GetRawPtr(nodes.first->right), GetRawPtr(nodes.second->right)});
    }
  }

  return true;
}

template <typename NodePtr>
std::string BinaryTreeToString(const NodePtr& tree) {
  using node_t = template_param_by_index_t<NodePtr, 0>;
  std::stringstream result;
  std::queue<const node_t*> nodes;
  std::unordered_set<const node_t*> visited;
  bool first = true;
  int null_nodes_pending = 0;

  result << "[";
  nodes.push(GetRawPtr(tree));

  while (!nodes.empty()) {
    auto node = nodes.front();
    nodes.pop();
    if (visited.count(node)) {
      throw std::runtime_error("Detected a cycle in the tree");
    }
    if (node) {
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
      PrintTo(result, node->data);
      result << '"';

      visited.insert(node);
      nodes.push(GetRawPtr(node->left));
      nodes.push(GetRawPtr(node->right));
    } else {
      null_nodes_pending++;
    }
  }

  result << "]";
  return result.str();
}

template <typename NodePtr>
int BinaryTreeHeight(const NodePtr& tree) {
  using node_t = template_param_by_index_t<NodePtr, 0>;
  std::stack<std::pair<const node_t*, int>> s{{{GetRawPtr(tree), 1}}};
  int height = 0;

  while (!s.empty()) {
    auto node = s.top();
    s.pop();
    if (!node.first) {
      continue;
    }

    height = std::max(height, node.second);
    s.push({GetRawPtr(node.first->right), node.second + 1});
    s.push({GetRawPtr(node.first->left), node.second + 1});
  }

  return height;
}

template <typename NodePtr>
int BinaryTreeSize(const NodePtr& tree) {
  using node_t = template_param_by_index_t<NodePtr, 0>;
  std::stack<const node_t*> s{{GetRawPtr(tree)}};
  int size = 0;

  while (!s.empty()) {
    auto node = s.top();
    s.pop();
    if (!node) {
      continue;
    }

    size++;
    s.push(GetRawPtr(node->right));
    s.push(GetRawPtr(node->left));
  }
  return size;
}
}  // namespace test_framework

using test_framework::MustFindNode;
