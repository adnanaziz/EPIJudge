#include <memory>
#include "list_node.h"

#pragma once

using std::shared_ptr;

shared_ptr<ListNode<int>> ReverseLinkedList(
    const shared_ptr<ListNode<int>>& head) {
  shared_ptr<ListNode<int>> prev = nullptr, curr = head;
  while (curr) {
    auto next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
