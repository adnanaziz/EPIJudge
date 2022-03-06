#include <memory>

#include "bst_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> RebuildBSTFromPreorderHelper(const vector<int>& preorder_sequence, 
                                                        int l_bound, int u_bound, int* root_indx_ptr) {
    int& root_indx = *root_indx_ptr;
    if (root_indx == preorder_sequence.size())
        return nullptr;
    
    int root = preorder_sequence[root_indx];
    if (root < l_bound || root > u_bound)
        return nullptr;

    root_indx++;
    auto& left_tree = RebuildBSTFromPreorderHelper(preorder_sequence, l_bound, root, root_indx_ptr);
    auto& right_tree = RebuildBSTFromPreorderHelper(preorder_sequence, root, u_bound, root_indx_ptr);
   
    return std::make_unique<BstNode<int>>(root,std::move(left_tree), std::move(right_tree));
}

unique_ptr<BstNode<int>> RebuildBSTFromPreorder(
    const vector<int>& preorder_sequence) {
    int root_indx = 0;
    return RebuildBSTFromPreorderHelper(preorder_sequence, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), &root_indx);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"preorder_sequence"};
  return GenericTestMain(args, "bst_from_preorder.cc", "bst_from_preorder.tsv",
                         &RebuildBSTFromPreorder, DefaultComparator{},
                         param_names);
}
