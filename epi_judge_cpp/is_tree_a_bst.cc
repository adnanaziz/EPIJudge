#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

bool AreKeyInRanges(const unique_ptr<BinaryTreeNode<int>>& tree, int l_bound, int r_bound) {
    if (tree == nullptr) {
        return true;
    }

    if (tree->data < l_bound || tree->data > r_bound) return false;

    return  AreKeyInRanges(tree->left, l_bound, tree->data) &&
        AreKeyInRanges(tree->right, tree->data, r_bound);


}

struct BSFNode {
    BinaryTreeNode<int > *node;
    int left_bound, right_bound;

};

bool IsBinaryTreeBST_BFS(const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (tree == nullptr) return true;
    
    std::queue<BSFNode> bsf_table;
    bsf_table.emplace(BSFNode{ tree.get(), std::numeric_limits<int>::min(), std::numeric_limits<int>::max() });

    while (!bsf_table.empty()) {
        const BSFNode& bn = bsf_table.front();
        if (bn.node != nullptr) {
            if (bn.node->data< bn.left_bound || bn.node->data > bn.right_bound)
                return false;

            bsf_table.emplace(BSFNode{ bn.node->left.get(), bn.left_bound, bn.node->data });
            bsf_table.emplace(BSFNode{ bn.node->right.get(), bn.node->data, bn.right_bound });
        }

        bsf_table.pop();
    }
    return true;
}

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  
    //return AreKeyInRanges(tree, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    return IsBinaryTreeBST_BFS(tree);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
