#include <memory>

#include "list_node.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> OverlappingNoCycleLists(
    shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2) {
  // Implement this placeholder.
  return nullptr;
}

void OverlappingNoCycleListsWrapper(TestTimer& timer,
                                    shared_ptr<ListNode<int>> p1,
                                    shared_ptr<ListNode<int>> p2,
                                    shared_ptr<ListNode<int>> common) {
  if (common) {
    if (!p1) {
      p1 = common;
    } else {
      auto l1 = p1;
      while (l1->next) {
        l1 = l1->next;
      }
      l1->next = common;
    }

    if (!p2) {
      p2 = common;
    } else {
      auto l2 = p2;
      while (l2->next) {
        l2 = l2->next;
      }
      l2->next = common;
    }
  }

  timer.Start();
  auto result = OverlappingNoCycleLists(p1, p2);
  timer.Stop();

  if (result != common) {
    throw TestFailureException("Invalid result");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "do_terminated_lists_overlap.tsv",
                    &OverlappingNoCycleListsWrapper);
  return 0;
}
