package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class BstMerge {

  private static BstNode<Integer> head;

  private static BstNode<Integer>
  buildSortedDoublyLinkedList(BstNode<Integer> L, int n) {
    head = L;
    return buildSortedDoublyLinkedListHelper(0, n);
  }

  // Build a BST from the (s + 1)-th to the e-th node in L.
  private static BstNode<Integer> buildSortedDoublyLinkedListHelper(int s,
                                                                    int e) {
    if (s >= e) {
      return null;
    }

    int m = s + ((e - s) / 2);
    BstNode<Integer> left = buildSortedDoublyLinkedListHelper(s, m);
    BstNode<Integer> curr = new BstNode<>(head.data);
    head = head.right;
    curr.left = left;
    curr.right = buildSortedDoublyLinkedListHelper(m + 1, e);
    return curr;
  }

  // Transform a BST into a circular sorted doubly linked list in-place,
  // return the head of the list.
  private static <T> BstNode<T> bstToDoublyLinkedList(BstNode<T> n) {
    // Empty subtree.
    if (n == null) {
      return null;
    }

    // Recursively build the list from left and right subtrees.
    BstNode<T> lHead = bstToDoublyLinkedList(n.left);
    BstNode<T> rHead = bstToDoublyLinkedList(n.right);

    // Append n to the list from left subtree.
    BstNode<T> lTail = null;
    if (lHead != null) {
      lTail = lHead.left;
      lTail.right = n;
      n.left = lTail;
      lTail = n;
    } else {
      lHead = lTail = n;
    }

    // Append the list from right subtree to n.
    BstNode<T> rTail = null;
    if (rHead != null) {
      rTail = rHead.left;
      lTail.right = rHead;
      rHead.left = lTail;
    } else {
      rTail = lTail;
    }
    rTail.right = lHead;
    lHead.left = rTail;

    return lHead;
  }

  // Count the list length till end.
  private static <T> int countLength(BstNode<T> L) {
    int length = 0;
    while (L != null) {
      ++length;
      L = L.right;
    }
    return length;
  }

  @EpiTest(testDataFile = "bst_merge.tsv")

  public static BstNode<Integer> mergeTwoBsts(BstNode<Integer> A,
                                              BstNode<Integer> B) {

    A = bstToDoublyLinkedList(A);
    B = bstToDoublyLinkedList(B);
    A.left.right = null;
    B.left.right = null;
    A.left = null;
    B.left = null;
    int ALength = countLength(A);
    int BLength = countLength(B);
    return buildSortedDoublyLinkedList(mergeTwoSortedLinkedLists(A, B),
                                       ALength + BLength);
  }

  // Merge two sorted linked lists, return the head of list.
  private static BstNode<Integer>
  mergeTwoSortedLinkedLists(BstNode<Integer> A, BstNode<Integer> B) {
    BstNode<Integer> dummyHead = new BstNode<>();
    BstNode<Integer> current = dummyHead;
    BstNode<Integer> p1 = A;
    BstNode<Integer> p2 = B;

    while (p1 != null && p2 != null) {
      if (Integer.compare(p1.data, p2.data) < 0) {
        current.right = p1;
        p1 = p1.right;
      } else {
        current.right = p2;
        p2 = p2.right;
      }
      current = current.right;
    }

    if (p1 != null) {
      current.right = p1;
    }
    if (p2 != null) {
      current.right = p2;
    }
    return dummyHead.right;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "BstMerge.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
