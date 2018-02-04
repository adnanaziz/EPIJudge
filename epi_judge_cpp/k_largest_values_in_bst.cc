#include <memory>
#include <vector>

#include "bst_node.h"

using std::unique_ptr;
using std::vector;

vector<int> FindKLargestInBST(const unique_ptr<BstNode<int>>& tree, int k) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "k"};
  GenericTestMain(args, "k_largest_values_in_bst.tsv", &FindKLargestInBST,
                  &UnorderedComparator<std::vector<int>>, param_names);
  return 0;
}
