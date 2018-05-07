
#pragma once

#include <memory>

using std::shared_ptr;


template <typename T>
struct ListNode {
  T data;
  shared_ptr<ListNode<T>> prev, next;
  
  ListNode(T data, const shared_ptr<ListNode<T>>& prev,
           const shared_ptr<ListNode<T>>& next)
      : data(data), prev(prev), next(next) {}
  
};

