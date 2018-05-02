package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ReverseSublist {
  @EpiTest(testDataFile = "reverse_sublist.tsv")

  public static ListNode<Integer> reverseSublist(ListNode<Integer> L, int start,
                                                 int finish) {

    ListNode<Integer> dummyHead = new ListNode<>(0, L);
    ListNode<Integer> sublistHead = dummyHead;
    int k = 1;
    while (k++ < start) {
      sublistHead = sublistHead.next;
    }

    // Reverse sublist.
    ListNode<Integer> sublistIter = sublistHead.next;
    while (start++ < finish) {
      ListNode<Integer> temp = sublistIter.next;
      sublistIter.next = temp.next;
      temp.next = sublistHead.next;
      sublistHead.next = temp;
    }
    return dummyHead.next;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ReverseSublist.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
