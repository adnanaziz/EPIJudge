package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class BstToSortedList {

  public static BstNode<Integer> bstToDoublyLinkedList(BstNode<Integer> tree) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "bst_to_sorted_list.tsv")
  public static List<Integer>
  bstToDoublyLinkedListWrapper(TestTimer timer, BstNode<Integer> tree)
      throws TestFailureException {
    timer.start();
    BstNode<Integer> list = bstToDoublyLinkedList(tree);
    timer.stop();

    if (list != null && list.left != null)
      throw new TestFailureException(
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
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
