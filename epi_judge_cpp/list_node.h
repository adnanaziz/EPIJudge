#include <iostream>
#include <memory>
#include "test_framework/test_utils_serialization_traits.h"

#pragma once

using std::make_shared;
using std::shared_ptr;

template <typename T>
struct ListNode {
  T data;

  // We need to use a shared pointer since multiple nodes may point to a
  // single node. For example, in the following list, two nodes, 1 and 4,
  // point to node 2.
  // 0->1->2->3->4
  //       ^     |
  //       |_____|
  shared_ptr<ListNode<T>> next;

  ListNode(T data = {}, shared_ptr<ListNode<T>> next = nullptr)
      : data(data), next(next) {}

  ~ListNode() {
    // Extra-long lists cause stack overflow with default destructor
    // implementation
    while (next && next.unique()) {
      auto next_next = next->next;
      next->next.reset();
      next = next_next;
    }
  }

  bool operator==(const ListNode<T>& that) const {
    const ListNode<T>* a = this;
    const ListNode<T>* b = &that;
    while (a && b) {
      if (a->data != b->data) {
        return false;
      }
      a = a->next.get();
      b = b->next.get();
    }
    return a == nullptr && b == nullptr;
  }
};

template <typename T>
bool EqualList(shared_ptr<ListNode<T>> a, shared_ptr<ListNode<T>> b) {
  return (!a && !b) || (a && b && *a == *b);
}

template <typename T>
std::shared_ptr<ListNode<T>> ConvertArrayToLinkedList(const std::vector<T>& v) {
  std::shared_ptr<ListNode<T>> head;
  for (auto it = rbegin(v); it != rend(v); ++it) {
    head = std::make_shared<ListNode<T>>(*it, head);
  }
  return head;
}

template <typename T>
struct SerializationTraits<shared_ptr<ListNode<T>>> {
  using serialization_type =
      shared_ptr<ListNode<typename SerializationTraits<T>::serialization_type>>;

  static const char* Name() {
    static std::string cached =
        std::string("linked_list(") + SerializationTraits<T>::Name() + ")";
    return cached.c_str();
  }

  static serialization_type Parse(const std::string& str) {
    auto v = SerializationTraits<std::vector<T>>::Parse(str);
    return ConvertArrayToLinkedList(v);
  }

  static serialization_type JsonParse(std::istream& in) {
    auto v = SerializationTraits<std::vector<T>>::JsonParse(in);
    return ConvertArrayToLinkedList(v);
  }

  static bool Equal(const serialization_type& a, const serialization_type& b) {
    return EqualList(a, b);
  }

  static void Print(std::ostream& out, serialization_type list) {
    std::set<serialization_type> visited;
    bool first = true;

    while (list) {
      if (first) {
        first = false;
      } else {
        out << " -> ";
      }

      if (visited.count(list)) {
        // Cycled linked list
        if (list->next != list) {
          PrintTo(out, list->data);
          out << " -> ... -> ";
        }
        PrintTo(out, list->data);
        out << " -> ...";
        break;
      } else {
        PrintTo(out, list->data);
        visited.insert(list);
      }
      list = list->next;
    }
  }
};
