
#pragma once

#include <memory>

#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::shared_ptr;

template <typename T>
struct BSTNode {
  T data;
  shared_ptr<BSTNode<T>> left, right;

  explicit BSTNode(const T& data) : data(data) {}
};

template <typename KeyT>
struct SerializationTraits<std::shared_ptr<BSTNode<KeyT>>>
    : BinaryTreeSerializationTraits<std::shared_ptr<BSTNode<KeyT>>, false> {};
