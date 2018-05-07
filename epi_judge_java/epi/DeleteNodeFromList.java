package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;
public class DeleteNodeFromList {

  // Assumes nodeToDelete is not tail.
  public static void deletionFromList(ListNode<Integer> nodeToDelete) {
    // TODO - you fill in here.
    return;
  }
  @EpiTest(testDataFile = "delete_node_from_list.tsv")
  public static ListNode<Integer> deleteListWrapper(TimedExecutor executor,
                                                    ListNode<Integer> head,
                                                    int nodeToDeleteIdx)
      throws Exception {
    ListNode<Integer> nodeToDelete = head;
    if (nodeToDelete == null)
      throw new RuntimeException("List is empty");
    while (nodeToDeleteIdx-- > 0) {
      if (nodeToDelete.next == null)
        throw new RuntimeException("Can't delete last node");
      nodeToDelete = nodeToDelete.next;
    }

    final ListNode<Integer> finalNodeToDelete = nodeToDelete;
    executor.run(() -> deletionFromList(finalNodeToDelete));

    return head;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DeleteNodeFromList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
