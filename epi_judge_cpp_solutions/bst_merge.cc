#include <memory>

#include "bst_prototype_shared_ptr.h"
#include "test_framework/generic_test.h"

using std::shared_ptr;

shared_ptr<BstNode<int>> BSTToDoublyListHelper(const shared_ptr<BstNode<int>>&);

shared_ptr<BstNode<int>> MergeTwoSortedLists(shared_ptr<BstNode<int>>,
                                             shared_ptr<BstNode<int>>);

void AppendNode(shared_ptr<BstNode<int>>*, shared_ptr<BstNode<int>>*);

// Build a BST from the (s + 1)-th to the e-th node in L.
shared_ptr<BstNode<int>> BuildBSTFromSortedDoublyListHelper(
    shared_ptr<BstNode<int>>* L, int s, int e) {
  shared_ptr<BstNode<int>> curr = nullptr;
  if (s < e) {
    int m = s + ((e - s) / 2);
    auto temp = BuildBSTFromSortedDoublyListHelper(L, s, m);
    curr = *L;
    curr->left = temp;
    *L = (*L)->right;
    curr->right = BuildBSTFromSortedDoublyListHelper(L, m + 1, e);
  }
  return curr;
}

shared_ptr<BstNode<int>> BuildBSTFromSortedDoublyList(
    shared_ptr<BstNode<int>> L, int n) {
  return BuildBSTFromSortedDoublyListHelper(&L, 0, n);
}

shared_ptr<BstNode<int>> BSTToDoublyList(const shared_ptr<BstNode<int>>& n) {
  auto result = BSTToDoublyListHelper(n);
  result->left->right = nullptr;  // breaks the link from tail to head.
  result->left = nullptr;         // breaks the link from head to tail.
  return result;
}

// Transform a BST into a circular sorted doubly linked list in-place,
// return the head of the list.
shared_ptr<BstNode<int>> BSTToDoublyListHelper(
    const shared_ptr<BstNode<int>>& n) {
  // Empty subtree.
  if (!n) {
    return nullptr;
  }

  // Recursively build the list from left and right subtrees.
  auto l_head(BSTToDoublyListHelper(n->left)),
      r_head(BSTToDoublyListHelper(n->right));

  // Append n to the list from left subtree.
  shared_ptr<BstNode<int>> l_tail = nullptr;
  if (l_head) {
    l_tail = l_head->left;
    l_tail->right = n;
    n->left = l_tail;
    l_tail = n;
  } else {
    l_head = l_tail = n;
  }

  // Append the list from right subtree to n.
  shared_ptr<BstNode<int>> r_tail = nullptr;
  if (r_head) {
    r_tail = r_head->left;
    l_tail->right = r_head;
    r_head->left = l_tail;
  } else {
    r_tail = l_tail;
  }
  r_tail->right = l_head, l_head->left = r_tail;

  return l_head;
}

// Count the list length till end.
int CountLength(shared_ptr<BstNode<int>> L) {
  int length = 0;
  while (L) {
    ++length, L = L->right;
  }
  return length;
}

shared_ptr<BstNode<int>> MergeTwoBSTs(shared_ptr<BstNode<int>> A,
                                      shared_ptr<BstNode<int>> B) {
  A = BSTToDoublyList(A), B = BSTToDoublyList(B);
  int A_length = CountLength(A), B_length = CountLength(B);
  return BuildBSTFromSortedDoublyList(MergeTwoSortedLists(A, B),
                                      A_length + B_length);
}

// Merges two sorted doubly linked lists, returns the head of merged list.
shared_ptr<BstNode<int>> MergeTwoSortedLists(shared_ptr<BstNode<int>> A,
                                             shared_ptr<BstNode<int>> B) {
  shared_ptr<BstNode<int>> sorted_head(new BstNode<int>(0));
  shared_ptr<BstNode<int>> tail = sorted_head;

  while (A && B) {
    AppendNode(A->data < B->data ? &A : &B, &tail);
  }

  if (A) {
    // Appends the remaining of A.
    AppendNode(&A, &tail);
  } else if (B) {
    // Appends the remaining of B.
    AppendNode(&B, &tail);
  }
  return sorted_head->right;
}

void AppendNode(shared_ptr<BstNode<int>>* node,
                shared_ptr<BstNode<int>>* tail) {
  (*tail)->right = *node;
  *tail = *node;  // Resets tail to the last node.
  *node = (*node)->right;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "bst_merge.cc", "bst_merge.tsv", &MergeTwoBSTs,
                         DefaultComparator{}, param_names);
}
