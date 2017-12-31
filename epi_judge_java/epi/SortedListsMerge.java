package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class SortedListsMerge {
  @EpiTest(testfile = "sorted_lists_merge.tsv")
  //@include
  public static ListNode<Integer> mergeTwoSortedLists(ListNode<Integer> L1,
                                                      ListNode<Integer> L2) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
