package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class EvenOddListMerge {
  @EpiTest(testfile = "even_odd_list_merge.tsv")

  public static ListNode<Integer> evenOddMerge(ListNode<Integer> L) {
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
