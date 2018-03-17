#include <memory>

#include "bst_node.h"
#include "test_framework/generic_test.h"

using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
  // Implement this placeholder.
  return nullptr;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder_sequence"};
  return GenericTestMain(args, timeout_seconds, "bst_from_preorder.tsv",
                         &RebuildBSTFromPreorder, DefaultComparator{},
                         param_names);
}
