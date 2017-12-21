#include <memory>
#include <vector>

#include "bst_node.h"

using std::unique_ptr;
using std::vector;

unique_ptr<BSTNode<int>> BuildMinHeightBSTFromSortedArray(
    const vector<int>& A) {
  // Implement this placeholder.
  return nullptr;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "bst_from_sorted_array.tsv",
                    &BuildMinHeightBSTFromSortedArray);
  return 0;
}
