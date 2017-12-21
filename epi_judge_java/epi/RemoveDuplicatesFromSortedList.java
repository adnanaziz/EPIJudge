package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class RemoveDuplicatesFromSortedList {
  @EpiTest(testfile = "remove_duplicates_from_sorted_list.tsv")

  public static ListNode<Integer> removeDuplicates(ListNode<Integer> L) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
