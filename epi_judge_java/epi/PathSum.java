package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class PathSum {
  @EpiTest(testfile = "path_sum.tsv")

  public static boolean hasPathSum(BinaryTreeNode<Integer> tree,
                                   int remainingWeight) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
