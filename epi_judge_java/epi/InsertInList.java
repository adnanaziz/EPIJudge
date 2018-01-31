package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

public class InsertInList {

  // Insert newNode after node.
  public static void insertAfter(ListNode<Integer> node,
                                 ListNode<Integer> newNode) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "insert_in_list.tsv")
  public static ListNode<Integer>
  insertListWrapper(TestTimer timer, ListNode<Integer> l, int nodeIdx,
                    int newNodeData) {
    ListNode<Integer> node = l;
    while (nodeIdx > 1) {
      node = node.next;
      --nodeIdx;
    }
    ListNode<Integer> newNode = new ListNode<Integer>(newNodeData, null);

    timer.start();
    insertAfter(node, newNode);
    timer.stop();

    return l;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
