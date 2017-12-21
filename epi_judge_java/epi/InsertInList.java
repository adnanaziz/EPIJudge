package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

public class InsertInList {
  // Insert newNode after node.
  public static void insertAfter(ListNode<Integer> node, ListNode<Integer> newNode) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "insert_in_list.tsv")
  public static ListNode<Integer> insertListWrapper(
      TestTimer timer, ListNode<Integer> L, int pos, int key) {
    ListNode<Integer> node = L;
    while (pos > 1) {
      node = node.next;
      --pos;
    }
    ListNode<Integer> newNode = new ListNode<Integer>(key, null);

    timer.start();
    insertAfter(node, newNode);
    timer.stop();

    return L;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
