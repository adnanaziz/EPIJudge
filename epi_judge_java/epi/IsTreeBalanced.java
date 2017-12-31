package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class IsTreeBalanced {

  @EpiTest(testfile = "is_tree_balanced.tsv")

  public static boolean isBalanced(BinaryTreeNode<Integer> tree) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
