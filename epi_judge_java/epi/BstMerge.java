package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class BstMerge {

  @EpiTest(testfile = "bst_merge.tsv")

  public static BstNode<Integer> mergeTwoBsts(BstNode<Integer> A,
                                              BstNode<Integer> B) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
