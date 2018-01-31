#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>

#include "list_node.h"
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> ListPivoting(const shared_ptr<ListNode<int>>& l,
                                       int x) {
  // Implement this placeholder.
  return nullptr;
}

std::vector<int> ListToVector(const shared_ptr<ListNode<int>>& l) {
  std::vector<int> v;
  ListNode<int>* it = l.get();
  while (it) {
    v.push_back(it->data);
    it = it->next.get();
  }
  return v;
}

void ListPivotingWrapper(TestTimer& timer, const shared_ptr<ListNode<int>>& l,
                         int x) {
  std::vector<int> original = ListToVector(l);
  timer.Start();
  std::shared_ptr<ListNode<int>> pivoted_list = ListPivoting(l, x);
  timer.Stop();
  vector<int> pivoted = ListToVector(pivoted_list);
  enum { LESS, EQ, GREATER } mode = LESS;
  for (auto& i : pivoted) {
    switch (mode) {
      case LESS:
        if (i == x) {
          mode = EQ;
        } else if (i > x) {
          mode = GREATER;
        }
        break;
      case EQ:
        if (i < x) {
          throw TestFailureException("List is not pivoted");
        } else if (i > x) {
          mode = GREATER;
        }
        break;
      case GREATER:
        if (i <= x) {
          throw TestFailureException("List is not pivoted");
        }
    }
  }
  std::sort(begin(original), end(original));
  std::sort(begin(pivoted), end(pivoted));
  if (original != pivoted) {
    throw TestFailureException("Result list contains different values");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "l", "x"};
  generic_test_main(argc, argv, param_names, "pivot_list.tsv",
                    &ListPivotingWrapper);
  return 0;
}
