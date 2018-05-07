package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.List;

public class BstToSortedList {

  private static class HeadAndTail {
    public BstNode<Integer> head;
    public BstNode<Integer> tail;

    public HeadAndTail(BstNode<Integer> head, BstNode<Integer> tail) {
      this.head = head;
      this.tail = tail;
    }
  }

  public static BstNode<Integer> bstToDoublyLinkedList(BstNode<Integer> tree) {

    return bstToDoublyLinkedListHelper(tree).head;
  }

  // Transforms a BST into a sorted doubly linked list in-place, and return the
  // head and tail of the list.
  private static HeadAndTail
  bstToDoublyLinkedListHelper(BstNode<Integer> tree) {
    // Empty subtree.
    if (tree == null) {
      return new HeadAndTail(null, null);
    }

    // Recursively build the list from left and right subtrees.
    HeadAndTail left = bstToDoublyLinkedListHelper(tree.left);
    HeadAndTail right = bstToDoublyLinkedListHelper(tree.right);

    // Append tree to the list from left subtree.
    if (left.tail != null) {
      left.tail.right = tree;
    }
    tree.left = left.tail;

    // Append the list from right subtree to tree.
    tree.right = right.head;
    if (right.head != null) {
      right.head.left = tree;
    }

    return new HeadAndTail(left.head != null ? left.head : tree,
                           right.tail != null ? right.tail : tree);
  }

  @EpiTest(testDataFile = "bst_to_sorted_list.tsv")
  public static List<Integer>
  bstToDoublyLinkedListWrapper(TimedExecutor executor, BstNode<Integer> tree)
      throws Exception {
    BstNode<Integer> list = executor.run(() -> bstToDoublyLinkedList(tree));

    if (list != null && list.left != null)
      throw new TestFailure(
          "Function must return the head of the list. Left link must be null");
    List<Integer> v = new ArrayList<>();
    while (list != null) {
      v.add(list.data);
      if (list.right != null && list.right.left != list)
        throw new RuntimeException("List is ill-formed");
      list = list.right;
    }
    return v;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "BstToSortedList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
