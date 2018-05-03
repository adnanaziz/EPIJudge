
#pragma once

#include <memory>

#include "test_framework/binary_tree_utils.h"
#include "test_framework/serialization_traits.h"

using std::unique_ptr;


template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  BinaryTreeNode<T>* parent;
  
  explicit BinaryTreeNode(const T& data) : data(data), parent(nullptr) {}
  
};


DECLARE_BINARY_TREE_TYPE(KeyT, std::unique_ptr<BinaryTreeNode<KeyT>>, true)
