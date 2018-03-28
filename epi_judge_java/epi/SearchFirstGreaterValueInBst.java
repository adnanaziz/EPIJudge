package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SearchFirstGreaterValueInBst {

  public static BstNode<Integer> findFirstGreaterThanK(BstNode<Integer> tree,
                                                       Integer k) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "search_first_greater_value_in_bst.tsv")
  public static int findFirstGreaterThanKWrapper(BstNode<Integer> tree,
                                                 Integer k) {
    BstNode<Integer> result = findFirstGreaterThanK(tree, k);
    return result != null ? result.data : -1;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
