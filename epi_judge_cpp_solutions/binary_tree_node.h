
#pragma once

#include <list>
#include <memory>
#include <random>

#include "test_framework/binary_tree_utils.h"
#include "test_framework/serialization_traits.h"

using std::unique_ptr;


template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  
  explicit BinaryTreeNode(const T& data) : data(data) {}
  BinaryTreeNode(T data, unique_ptr<BinaryTreeNode<T>> left,
                 unique_ptr<BinaryTreeNode<T>> right)
      : data(data), left(std::move(left)), right(std::move(right)) {}
  
};


DECLARE_BINARY_TREE_TYPE(KeyT, std::unique_ptr<BinaryTreeNode<KeyT>>, false)
