#include <memory>

#include "bst_prototype_shared_ptr.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<BstNode<int>> BuildBSTFromSortedDoublyListHelper(
    shared_ptr<BstNode<int>>* l_ref, int start, int end) {

    if (start >= end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;

    auto left = BuildBSTFromSortedDoublyListHelper(l_ref, start, mid);
    auto curr = *l_ref;
    *l_ref = (*l_ref)->right;

    curr->left = left;
    curr->right = BuildBSTFromSortedDoublyListHelper(l_ref, mid + 1, end);

    return curr;
}

// Returns the root of the corresponding BST. The prev and next fields of the
// list nodes are used as the BST nodes left and right fields, respectively.
// The length of the list is given.
shared_ptr<BstNode<int>> BuildBSTFromSortedDoublyList(
    shared_ptr<BstNode<int>> l, int length) {
    if (l == nullptr) return nullptr;
    return BuildBSTFromSortedDoublyListHelper(&l, 0, length);
}

struct HeadAndTail {
    shared_ptr<BstNode<int>> head, tail;
};

HeadAndTail BSTToDoublyLinkedListHelper(
    const shared_ptr<BstNode<int>>& tree) {

    if (!tree) {
        return { nullptr, nullptr };
    }

    auto left = BSTToDoublyLinkedListHelper(tree->left);
    auto right = BSTToDoublyLinkedListHelper(tree->right);

    if (left.tail) {
        left.tail->right = tree;
    }

    tree->left = left.tail;
    tree->right = right.head;

    if (right.head) {
        right.head->left = tree;
    }

    return { left.head ? left.head : tree, right.tail ? right.tail : tree };
}

shared_ptr<BstNode<int>> BSTToDoublyLinkedList(
    const shared_ptr<BstNode<int>>& tree) {
    return BSTToDoublyLinkedListHelper(tree).head;
}

int CountNodes(shared_ptr<BstNode<int>> list) {
    int count = 0;
    while (list) {
        list = list->right;
        count++;
    }
    return count;
}

void AddNode(shared_ptr<BstNode<int>>* node,
             shared_ptr<BstNode<int>>* tail) {
    (*tail)->right = (*node);
    /*
    if((*tail)->left == nullptr)
        (*node)->left = nullptr;
    else*/
        (*node)->left = *tail;
    (*tail) = (*node);

    (*node) = (*node)->right;
}

shared_ptr<BstNode<int>> MergeDoublLinkList(shared_ptr<BstNode<int>> l1, 
                                            shared_ptr<BstNode<int>> l2) {
    shared_ptr<BstNode<int>> dummy_head(new BstNode<int>(123)); //= std::make_shared<BstNode<int>(0)>{};
    auto tail = dummy_head;

    while (l1 && l2) {
        AddNode(l1->data <= l2->data? &l1: &l2, &tail);
    }

    auto rmn = l1 ? l1 : l2;
    if(rmn){
        rmn->left = tail;
        tail->right = rmn;
    }
    
    dummy_head->right->left = nullptr;
    return dummy_head->right;
}

struct Values {
    std::string str, rev;

};

Values PrintDoublList(shared_ptr<BstNode<int>> list) {
    std::string strght, rvrs;
    auto prev = list;
    while (list) {
        strght += std::to_string(list->data) + " ";
        prev = list;
        list = list->right;
    }
    while (prev) {
        rvrs += std::to_string(prev->data) + " ";
        prev = prev->left;
    }

    return {strght, rvrs};
}

shared_ptr<BstNode<int>> MergeTwoBSTs(shared_ptr<BstNode<int>> A,
                                      shared_ptr<BstNode<int>> B) {
    shared_ptr<BstNode<int>> a_lst = BSTToDoublyLinkedList(A);
    shared_ptr<BstNode<int>> b_lst = BSTToDoublyLinkedList(B);

    PrintDoublList(a_lst);
    PrintDoublList(b_lst);

    int a_len = CountNodes(a_lst);
    int b_len = CountNodes(b_lst);

    auto final_lst = MergeDoublLinkList(a_lst, b_lst);
    auto rtn = PrintDoublList(final_lst);
    return BuildBSTFromSortedDoublyList(final_lst, a_len + b_len);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "bst_merge.cc", "bst_merge.tsv", &MergeTwoBSTs,
                         DefaultComparator{}, param_names);
}
