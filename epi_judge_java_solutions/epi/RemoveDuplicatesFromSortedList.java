package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class RemoveDuplicatesFromSortedList {
  @EpiTest(testDataFile = "remove_duplicates_from_sorted_list.tsv")

  public static ListNode<Integer> removeDuplicates(ListNode<Integer> L) {

    ListNode<Integer> iter = L;
    while (iter != null) {
      // Uses nextDistinct to find the next distinct value.
      ListNode<Integer> nextDistinct = iter.next;
      while (nextDistinct != null && nextDistinct.data == iter.data) {
        nextDistinct = nextDistinct.next;
      }
      iter.next = nextDistinct;
      iter = nextDistinct;
    }
    return L;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RemoveDuplicatesFromSortedList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
