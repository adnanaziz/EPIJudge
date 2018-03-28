package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ReverseSublist {
  @EpiTest(testfile = "reverse_sublist.tsv")

  public static ListNode<Integer> reverseSublist(ListNode<Integer> L, int start,
                                                 int finish) {
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
