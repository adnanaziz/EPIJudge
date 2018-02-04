#include <memory>
#include <vector>

#include "bst_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/test_failure_exception.h"

using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> BuildMinHeightBSTFromSortedArray(
    const vector<int>& A) {
  // Implement this placeholder.
  return nullptr;
}

int BuildMinHeightBSTFromSortedArrayWrapper(TestTimer& timer,
                                            const vector<int>& A) {
  timer.Start();
  unique_ptr<BstNode<int>> result = BuildMinHeightBSTFromSortedArray(A);
  timer.Stop();

  if (GenerateInorder(result) != A) {
    throw TestFailureException("Result binay tree mismatches input array");
  }
  return BinaryTreeHeight(result);
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "A"};
  GenericTestMain(args, "bst_from_sorted_array.tsv",
                  &BuildMinHeightBSTFromSortedArrayWrapper, DefaultComparator{},
                  param_names);
  return 0;
}
