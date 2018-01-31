package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

public class DeleteNodeFromList {

  // Assumes nodeToDelete is not tail.
  public static void deletionFromList(ListNode<Integer> nodeToDelete) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "delete_node_from_list.tsv")
  public static ListNode<Integer> deleteListWrapper(TestTimer timer,
                                                    ListNode<Integer> head,
                                                    int nodeToDeleteIdx) {
    ListNode<Integer> nodeToDelete = head;
    if (nodeToDelete == null)
      throw new RuntimeException("List is empty");
    while (nodeToDeleteIdx-- > 0) {
      if (nodeToDelete.next == null)
        throw new RuntimeException("Can't delete last node");
      nodeToDelete = nodeToDelete.next;
    }

    timer.start();
    deletionFromList(nodeToDelete);
    timer.stop();

    return head;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
