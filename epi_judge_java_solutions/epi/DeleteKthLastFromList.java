package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class DeleteKthLastFromList {
  @EpiTest(testDataFile = "delete_kth_last_from_list.tsv")

  // Assumes L has at least k nodes, deletes the k-th last node in L.
  public static ListNode<Integer> removeKthLast(ListNode<Integer> L, int k) {

    ListNode<Integer> dummyHead = new ListNode<>(0, L);
    ListNode<Integer> first = dummyHead.next;
    while (k-- > 0) {
      first = first.next;
    }

    ListNode<Integer> second = dummyHead;
    while (first != null) {
      second = second.next;
      first = first.next;
    }
    // second points to the (k + 1)-th last node, deletes its successor.
    second.next = second.next.next;
    return dummyHead.next;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DeleteKthLastFromList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
