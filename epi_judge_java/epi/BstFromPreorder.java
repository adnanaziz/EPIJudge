package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class BstFromPreorder {
  @EpiTest(testfile = "bst_from_preorder.tsv")

  public static BstNode<Integer>
  rebuildBSTFromPreorder(List<Integer> preorderSequence) {
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
