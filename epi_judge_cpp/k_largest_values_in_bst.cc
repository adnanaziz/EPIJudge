#include <memory>
#include <vector>

#include "bst_node.h"

using std::unique_ptr;
using std::vector;

vector<int> FindKLargestInBST(const unique_ptr<BSTNode<int>>& tree, int k) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "k_largest_values_in_bst.tsv",
                    &FindKLargestInBST, &UnorderedComparator<std::vector<int>>);
  return 0;
}
