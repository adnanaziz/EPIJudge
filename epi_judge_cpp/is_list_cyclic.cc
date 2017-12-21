#include <memory>

#include "list_node.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head) {
  // Implement this placeholder.
  return nullptr;
}

void HasCycleWrapper(TestTimer& timer, const shared_ptr<ListNode<int>>& head,
                     int cycle_idx) {
  int cycle_length = 0;
  if (cycle_idx != -1) {
    if (!head) {
      throw std::runtime_error("Can't cycle empty list");
    }
    shared_ptr<ListNode<int>> cycle_start, cursor = head;
    while (cursor->next) {
      if (cursor->data == cycle_idx) {
        cycle_start = cursor;
      }
      cursor = cursor->next;
      cycle_length += !!cycle_start;
    }
    if (cursor->data == cycle_idx) {
      cycle_start = cursor;
    }
    if (!cycle_start) {
      throw std::runtime_error("Can't find a cycle start");
    }
    cursor->next = cycle_start;
    cycle_length++;
  }
  timer.Start();
  shared_ptr<ListNode<int>> result = HasCycle(head);
  timer.Stop();

  if (cycle_idx == -1) {
    if (result != nullptr) {
      throw TestFailureException("Found a non-existing cycle");
    }
  } else {
    if (result == nullptr) {
      throw TestFailureException("Existing cycle was not found");
    }

    auto cursor = result;
    do {
      cursor = cursor->next;
      cycle_length--;
      if (!cursor || cycle_length < 0) {
        throw TestFailureException(
            "Returned node does not belong to the cycle or is not the "
            "closest node to the head");
      }
    } while (cursor != result);

    if (cycle_length != 0) {
      throw TestFailureException(
          "Returned node does not belong to the cycle or is not the closest "
          "node to the head");
    }
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "is_list_cyclic.tsv", &HasCycleWrapper);
  return 0;
}
