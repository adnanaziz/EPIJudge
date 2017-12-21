package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class SumRootToLeaf {
  @EpiTest(testfile = "sum_root_to_leaf.tsv")

  public static int sumRootToLeaf(BinaryTreeNode<Integer> tree) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
