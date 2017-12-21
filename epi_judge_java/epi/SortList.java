package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class SortList {
  @EpiTest(testfile = "sort_list.tsv")

  public static ListNode<Integer> stableSortList(ListNode<Integer> L) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
