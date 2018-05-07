
#pragma once

#include <memory>

#include "test_framework/binary_tree_utils.h"
#include "test_framework/serialization_traits.h"

using std::shared_ptr;


template <typename T>
struct BstNode {
  T data;
  shared_ptr<BstNode<T>> left, right;
  
  explicit BstNode(const T& data) : data(data) {}
  
};


DECLARE_BINARY_TREE_TYPE(KeyT, std::shared_ptr<BstNode<KeyT>>, false)
