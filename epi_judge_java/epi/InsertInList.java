package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

public class InsertInList {

  // Insert newNode after node.
  public static void insertAfter(ListNode<Integer> node,
                                 ListNode<Integer> newNode) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "insert_in_list.tsv")
  public static ListNode<Integer>
  insertListWrapper(TimedExecutor executor, ListNode<Integer> l, int nodeIdx,
                    int newNodeData) throws Exception {
    ListNode<Integer> node = l;
    while (nodeIdx > 1) {
      node = node.next;
      --nodeIdx;
    }
    ListNode<Integer> newNode = new ListNode<Integer>(newNodeData, null);

    final ListNode<Integer> finalNode = node;
    executor.run(() -> insertAfter(finalNode, newNode));

    return l;
  }

  public static void main(String[] args) {
    // The timeout is set to 15 seconds for each test case.
    // If your program ends with TIMEOUT error, and you want to try longer time
    // limit, you can extend the limit by changing the following line.
    long timeoutSeconds = 15;

    System.exit(
        GenericTest
            .runFromAnnotations(args, timeoutSeconds,
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
