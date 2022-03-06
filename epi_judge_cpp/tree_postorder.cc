#include <memory>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

vector<int> InvertedPreorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
    vector<int> result;
    std::stack<BinaryTreeNode<int>*> path;
    path.emplace(tree.get());

    while (!path.empty()) {
        auto* curr = path.top();
        path.pop();

        if (curr != nullptr) {
            result.push_back(curr->data);
            path.emplace(curr->left.get());
            path.emplace(curr->right.get());
        }
    }
    return result;
}

vector<int> PostorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
    /*vector<int> sequence = InvertedPreorderTraversal(tree);
    std::reverse(sequence.begin(), sequence.end());
    return sequence;
    */

    if (tree == nullptr)
        return {};

    vector<int> sequence;
    std::stack<BinaryTreeNode<int>*> path;

    BinaryTreeNode<int>* prev = nullptr;
    path.emplace(tree.get());

    while (!path.empty()) {
        auto curr = path.top();
        if (prev == nullptr || prev->left.get() == curr || prev->right.get() == curr) {

            if (curr->left != nullptr) {
                path.emplace(curr->left.get());
            }
            else if (curr->right != nullptr) {
                path.emplace(curr->right.get());
            }
            else {
                sequence.emplace_back(curr->data);
                path.pop();
            }
        }
        else if (curr->left.get() == prev) {
            
            if (curr->right != nullptr) {
                path.emplace(curr->right.get());
            }
            else {
                sequence.emplace_back(curr->data);
                path.pop();
            }
        }
        else {
            sequence.emplace_back(curr->data);
            path.pop();
        }
        prev = curr;
    }

    return sequence;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_postorder.cc", "tree_postorder.tsv",
                         &PostorderTraversal, DefaultComparator{}, param_names);
}
