
#pragma once

#include <memory>

#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::unique_ptr;

template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  BinaryTreeNode<T>* parent;

  explicit BinaryTreeNode(const T& data) : data(data), parent(nullptr) {}
};

template <typename KeyT>
struct SerializationTraits<unique_ptr<BinaryTreeNode<KeyT>>>
    : BinaryTreeSerializationTraits<unique_ptr<BinaryTreeNode<KeyT>>, true> {};
