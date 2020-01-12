package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ZipList {
  @EpiTest(testDataFile = "zip_list.tsv")

  public static ListNode<Integer> zippingLinkedList(ListNode<Integer> L) {

    if (L == null || L.next == null) {
      return L;
    }

    // Find the second half of L.
    ListNode<Integer> slow = L, fast = L;
    while (fast != null && fast.next != null) {
      fast = fast.next.next;
      slow = slow.next;
    }

    ListNode<Integer> firstHalfHead = L, secondHalfHead = slow.next;
    slow.next = null; // Splits the list into two lists.
    secondHalfHead = ReverseList.reverseList(secondHalfHead);

    // Interleave the first half and the reversed of the second half.
    ListNode<Integer> firstHalfIter = firstHalfHead;
    ListNode<Integer> secondHalfIter = secondHalfHead;
    while (secondHalfIter != null) {
      ListNode<Integer> temp = secondHalfIter.next;
      secondHalfIter.next = firstHalfIter.next;
      firstHalfIter.next = secondHalfIter;
      firstHalfIter = firstHalfIter.next.next;
      secondHalfIter = temp;
    }
    return L;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ZipList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
