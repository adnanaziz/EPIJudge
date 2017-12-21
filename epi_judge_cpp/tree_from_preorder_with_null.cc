#include <string>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/test_timer.h"

using std::string;
using std::vector;

unique_ptr<BinaryTreeNode<int>> ReconstructPreorder(
    const vector<int*>& preorder) {
  // Implement this placeholder.
  return nullptr;
}

unique_ptr<BinaryTreeNode<int>> ReconstructPreorderWrapper(
    TestTimer& timer, const vector<string>& preorder) {
  vector<int> values;
  vector<int*> ptrs;
  values.reserve(preorder.size());
  for (auto& s : preorder) {
    if (s == "null") {
      ptrs.push_back(nullptr);
    } else {
      int i = std::stoi(s);
      values.push_back(i);
      ptrs.push_back(&values.back());
    }
  }

  timer.Start();
  auto result = ReconstructPreorder(ptrs);
  timer.Stop();
  return result;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "tree_from_preorder_with_null.tsv",
                    &ReconstructPreorderWrapper);
  return 0;
}
