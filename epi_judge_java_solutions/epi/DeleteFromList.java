package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

public class DeleteFromList {

  // Delete the node immediately following aNode. Assumes aNode is not a tail.
  public static void deleteList(ListNode<Integer> aNode) {

    aNode.next = aNode.next.next;
  }

  @EpiTest(testDataFile = "delete_from_list.tsv")
  public static ListNode<Integer>
  deleteListWrapper(TimedExecutor executor, ListNode<Integer> head, int nodeIdx)
      throws Exception {
    ListNode<Integer> nodeToDelete = head;
    ListNode<Integer> prev = null;

    if (nodeToDelete == null)
      throw new RuntimeException("List is empty");
    while (nodeIdx-- > 0) {
      if (nodeToDelete.next == null)
        throw new RuntimeException("Can't delete last node");
      prev = nodeToDelete;
      nodeToDelete = nodeToDelete.next;
    }

    final ListNode<Integer> finalPrev = prev;

    executor.run(() -> deleteList(finalPrev));

    return head;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DeleteFromList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
