#include <memory>
#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> L) {
  // TODO - you fill in here.
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "sort_list.cc", "sort_list.tsv", &StableSortList,
                         DefaultComparator{}, param_names);
}
