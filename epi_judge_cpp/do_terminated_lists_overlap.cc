#include <memory>

#include "list_node.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> OverlappingNoCycleLists(
    shared_ptr<ListNode<int>> l0, shared_ptr<ListNode<int>> l1) {
  // Implement this placeholder.
  return nullptr;
}

void OverlappingNoCycleListsWrapper(TestTimer& timer,
                                    shared_ptr<ListNode<int>> l0,
                                    shared_ptr<ListNode<int>> l1,
                                    shared_ptr<ListNode<int>> common) {
  if (common) {
    if (l0) {
      auto i = l0;
      while (i->next) {
        i = i->next;
      }
      i->next = common;
    } else {
      l0 = common;
    }

    if (l1) {
      auto i = l1;
      while (i->next) {
        i = i->next;
      }
      i->next = common;
    } else {
      l1 = common;
    }
  }

  timer.Start();
  auto result = OverlappingNoCycleLists(l0, l1);
  timer.Stop();

  if (result != common) {
    throw TestFailureException("Invalid result");
  }
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "l0", "l1", "common"};
  GenericTestMain(args, "do_terminated_lists_overlap.tsv",
                  &OverlappingNoCycleListsWrapper, DefaultComparator{},
                  param_names);
  return 0;
}
