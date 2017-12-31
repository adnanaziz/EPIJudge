package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class TreeFromPreorderInorder {
  @EpiTest(testfile = "tree_from_preorder_inorder.tsv")

  public static BinaryTreeNode<Integer>
  binaryTreeFromPreorderInorder(List<Integer> preorder, List<Integer> inorder) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
