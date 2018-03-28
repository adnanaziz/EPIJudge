package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IsTreeBalanced {

  @EpiTest(testfile = "is_tree_balanced.tsv")

  public static boolean isBalanced(BinaryTreeNode<Integer> tree) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
