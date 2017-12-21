#include <set>
#include <stdexcept>

#include "list_node.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> L1,
                                           shared_ptr<ListNode<int>> L2) {
  // Implement this placeholder.
  return nullptr;
}

void OverlappingListsWrapper(TestTimer& timer, shared_ptr<ListNode<int>> l1,
                             shared_ptr<ListNode<int>> l2,
                             shared_ptr<ListNode<int>> common, int cycle1,
                             int cycle2) {
  if (common) {
    if (!l1) {
      l1 = common;
    } else {
      auto it = l1;
      while (it->next) {
        it = it->next;
      }
      it->next = common;
    }

    if (!l2) {
      l2 = common;
    } else {
      auto it = l2;
      while (it->next) {
        it = it->next;
      }
      it->next = common;
    }
  }

  if (cycle1 != -1 && l1) {
    auto last = l1;
    while (last->next) {
      last = last->next;
    }
    auto it = l1;
    while (cycle1-- > 0) {
      if (!it) {
        throw std::runtime_error("Invalid input data");
      }
      it = it->next;
    }
    last->next = it;
  }

  if (cycle2 != -1 && l2) {
    auto last = l2;
    while (last->next) {
      last = last->next;
    }
    auto it = l2;
    while (cycle2-- > 0) {
      if (!it) {
        throw std::runtime_error("Invalid input data");
      }
      it = it->next;
    }
    last->next = it;
  }

  std::set<shared_ptr<ListNode<int>>> common_nodes;
  auto it = common;
  while (it && common_nodes.count(it) == 0) {
    common_nodes.insert(it);
    it = it->next;
  }

  timer.Start();
  auto result = OverlappingLists(l1, l2);
  timer.Stop();

  if (!((common_nodes.empty() && result == nullptr) ||
        common_nodes.count(result) > 0)) {
    throw TestFailureException("Invalid result");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "do_lists_overlap.tsv",
                    &OverlappingListsWrapper);
  return 0;
}
