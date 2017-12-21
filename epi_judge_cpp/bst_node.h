
#pragma once

#include <memory>

#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::unique_ptr;

template <typename T>
struct BSTNode {
  T data;
  unique_ptr<BSTNode<T>> left, right;

  explicit BSTNode(const T& data) : data(data) {}

  BSTNode(T data, unique_ptr<BSTNode<T>> left, unique_ptr<BSTNode<T>> right)
      : data(data), left(std::move(left)), right(std::move(right)) {}
};

template <typename KeyT>
struct SerializationTraits<std::unique_ptr<BSTNode<KeyT>>>
    : BinaryTreeSerializationTraits<std::unique_ptr<BSTNode<KeyT>>, false> {};
