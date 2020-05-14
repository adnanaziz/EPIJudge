package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SortList {
  @EpiTest(testDataFile = "sort_list.tsv")

  public static ListNode<Integer> stableSortList(ListNode<Integer> L) {

    // Base cases: L is empty or a single node, nothing to do.
    if (L == null || L.next == null) {
      return L;
    }

    // Find the midpoint of L using a slow and a fast pointer.
    ListNode<Integer> preSlow = null, slow = L, fast = L;
    while (fast != null && fast.next != null) {
      preSlow = slow;
      fast = fast.next.next;
      slow = slow.next;
    }

    if (preSlow != null) {
      preSlow.next = null; // Splits the list into two equal-sized lists.
    }
    return SortedListsMerge.mergeTwoSortedLists(stableSortList(L),
                                                stableSortList(slow));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SortList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
