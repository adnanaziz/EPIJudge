#include <set>
#include <stdexcept>

#define main _main
#include "do_terminated_lists_overlap.cc"
#undef main
#define main __main
#include "is_list_cyclic.cc"
#undef main
#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

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

  // l0 and l1 do not end in the same cycle.
  if (temp != root0) {
    return nullptr;  // Cycles are disjoint.
  }

  // l0 and l1 end in the same cycle, locate the overlapping node if they
  // first overlap before cycle starts.
  int stem0_length = Distance(l0, root0), stem1_length = Distance(l1, root1);
  AdvanceListByK(abs(stem0_length - stem1_length),
                 stem0_length > stem1_length ? &l0 : &l1);
  while (l0 != l1 && l0 != root0 && l1 != root1) {
    l0 = l0->next, l1 = l1->next;
  }

  // If l0 == l1 before reaching root0, it means the overlap first occurs
  // before the cycle starts; otherwise, the first overlapping node is not
  // unique, so we can return any node on the cycle.
  return l0 == l1 ? l0 : root0;
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
  return GenericTestMain(args, "do_lists_overlap.cc", "do_lists_overlap.tsv", &OverlappingListsWrapper, DefaultComparator{}, param_names);
}
// clang-format on
