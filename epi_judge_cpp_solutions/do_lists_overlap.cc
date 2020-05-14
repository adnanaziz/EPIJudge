#include <set>
#include <stdexcept>

#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

#define main _main
#include "do_terminated_lists_overlap.cc"
#undef main
#define main __main
#include "is_list_cyclic.cc"
#undef main

int Distance(shared_ptr<ListNode<int>> a, shared_ptr<ListNode<int>> b);

shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> l0,
                                           shared_ptr<ListNode<int>> l1) {
  // Store the start of cycle if any.
  auto root0 = HasCycle(l0), root1 = HasCycle(l1);

  if (!root0 && !root1) {
    // Both lists don't have cycles.
    return OverlappingNoCycleLists(l0, l1);
  } else if ((root0 && !root1) || (!root0 && root1)) {
    // One list has cycle, and one list has no cycle.
    return nullptr;
  }
  // Both lists have cycles.
  auto temp = root1;
  do {
    temp = temp->next;
  } while (temp != root0 && temp != root1);

  return temp == root0 ? root1 : nullptr;
}

// Calculates the distance between a and b.
int Distance(shared_ptr<ListNode<int>> a, shared_ptr<ListNode<int>> b) {
  int dis = 0;
  while (a != b) {
    a = a->next, ++dis;
  }
  return dis;
}

void OverlappingListsWrapper(TimedExecutor& executor,
                             shared_ptr<ListNode<int>> l0,
                             shared_ptr<ListNode<int>> l1,
                             shared_ptr<ListNode<int>> common, int cycle0,
                             int cycle1) {
  if (common) {
    if (!l0) {
      l0 = common;
    } else {
      auto it = l0;
      while (it->next) {
        it = it->next;
      }
      it->next = common;
    }

    if (!l1) {
      l1 = common;
    } else {
      auto it = l1;
      while (it->next) {
        it = it->next;
      }
      it->next = common;
    }
  }

  if (cycle0 != -1 && l0) {
    auto last = l0;
    while (last->next) {
      last = last->next;
    }
    auto it = l0;
    while (cycle0-- > 0) {
      if (!it) {
        throw std::runtime_error("Invalid input data");
      }
      it = it->next;
    }
    last->next = it;
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

  std::set<shared_ptr<ListNode<int>>> common_nodes;
  auto it = common;
  while (it && common_nodes.count(it) == 0) {
    common_nodes.insert(it);
    it = it->next;
  }

  auto result = executor.Run([&] { return OverlappingLists(l0, l1); });

  if (!((common_nodes.empty() && result == nullptr) ||
        common_nodes.count(result) > 0)) {
    throw TestFailure("Invalid result");
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"executor", "l0", "l1", "common", "cycle0", "cycle1"};
  return GenericTestMain(args, "do_lists_overlap.cc", "do_lists_overlap.tsv", &OverlappingListsWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
