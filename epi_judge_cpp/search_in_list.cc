#include <memory>

#include "list_node.h"

using std::shared_ptr;

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L, int key) {
  // Implement this placeholder.
  return nullptr;
}

int SearchListWrapper(shared_ptr<ListNode<int>> L, int key) {
  auto result = SearchList(L, key);
  return result ? result->data : -1;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "key"};
  GenericTestMain(args, "search_in_list.tsv", &SearchListWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
