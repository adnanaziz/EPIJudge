#include <memory>
#include <vector>

#include "bst_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::unique_ptr;
using std::vector;

struct Interval;
void RangeLookupInBSTHelper(const unique_ptr<BstNode<int>>&, const Interval&,
                            vector<int>*);

struct Interval {
  int left, right;
};

vector<int> RangeLookupInBST(const unique_ptr<BstNode<int>>& tree,
                             const Interval& interval) {
  vector<int> result;
  RangeLookupInBSTHelper(tree, interval, &result);
  return result;
}

void RangeLookupInBSTHelper(const unique_ptr<BstNode<int>>& tree,
                            const Interval& interval, vector<int>* result) {
  if (tree == nullptr) {
    return;
  }
  if (interval.left <= tree->data && tree->data <= interval.right) {
    // tree->data lies in the interval.
    RangeLookupInBSTHelper(tree->left, interval, result);
    result->emplace_back(tree->data);
    RangeLookupInBSTHelper(tree->right, interval, result);
  } else if (interval.left > tree->data) {
    RangeLookupInBSTHelper(tree->right, interval, result);
  } else {  // interval.right > tree->data
    RangeLookupInBSTHelper(tree->left, interval, result);
  }
}

namespace test_framework {
template <>
struct SerializationTrait<Interval> : UserSerTrait<Interval, int, int> {
  static std::vector<std::string> GetMetricNames(const std::string& arg_name) {
    return {FmtStr("length({})", arg_name)};
  }

  static std::vector<int> GetMetrics(const Interval& x) {
    return {x.right - x.left};
  }
};
}  // namespace test_framework

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "interval"};
  return GenericTestMain(args, "range_lookup_in_bst.cc",
                         "range_lookup_in_bst.tsv", &RangeLookupInBST,
                         DefaultComparator{}, param_names);
}
