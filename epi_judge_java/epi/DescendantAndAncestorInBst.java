package epi;

import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

public class DescendantAndAncestorInBst {

  public static boolean
  pairIncludesAncestorAndDescendantOfM(BstNode<Integer> possibleAncOrDesc0,
                                       BstNode<Integer> possibleAncOrDesc1,
                                       BstNode<Integer> middle) {
    // Implement this placeholder.
    return true;
  }

  @EpiTest(testfile = "descendant_and_ancestor_in_bst.tsv")
  public static boolean pairIncludesAncestorAndDescendantOfMWrapper(
      TestTimer timer, BstNode<Integer> tree, int possibleAncOrDesc0,
      int possibleAncOrDesc1, int middle) {
    BstNode<Integer> candidate0 =
        BinaryTreeUtils.mustFindNode(tree, possibleAncOrDesc0);
    BstNode<Integer> candidate1 =
        BinaryTreeUtils.mustFindNode(tree, possibleAncOrDesc1);
    BstNode<Integer> middleNode = BinaryTreeUtils.mustFindNode(tree, middle);

    timer.start();
    boolean result = pairIncludesAncestorAndDescendantOfM(
        candidate0, candidate1, middleNode);
    timer.stop();
    return result;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
