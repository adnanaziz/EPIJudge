package epi;

import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

public class DescendantAndAncestorInBst {
  public static boolean pairIncludesAncestorAndDescendantOfM(BstNode<Integer> possibleAncOrDesc0,
      BstNode<Integer> possibleAncOrDesc1, BstNode<Integer> middle) {
    // Implement this placeholder.
    return true;
  }

  @EpiTest(testfile = "descendant_and_ancestor_in_bst.tsv")
  public static boolean pairIncludesAncestorAndDescendantOfMWrapper(
      TestTimer timer, BstNode<Integer> tree, int candidate1Idx, int candidate2Idx, int middleIdx) {
    BstNode<Integer> candidate1 = BinaryTreeUtils.mustFindNode(tree, candidate1Idx);
    BstNode<Integer> candidate2 = BinaryTreeUtils.mustFindNode(tree, candidate2Idx);
    BstNode<Integer> middle = BinaryTreeUtils.mustFindNode(tree, middleIdx);

    timer.start();
    boolean result = pairIncludesAncestorAndDescendantOfM(candidate1, candidate2, middle);
    timer.stop();
    return result;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
