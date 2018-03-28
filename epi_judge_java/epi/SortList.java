package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SortList {
  @EpiTest(testfile = "sort_list.tsv")

  public static ListNode<Integer> stableSortList(ListNode<Integer> L) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
