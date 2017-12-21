package epi;

import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

public class LowestCommonAncestorInBst {
  // Input nodes are nonempty and the key at s is less than or equal to that at
  // b.
  public static BstNode<Integer> findLCA(
      BstNode<Integer> tree, BstNode<Integer> s, BstNode<Integer> b) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "lowest_common_ancestor_in_bst.tsv")
  public static int lcaWrapper(TestTimer timer, BstNode<Integer> root, Integer key1, int key2)
      throws TestFailureException {
    BstNode<Integer> node1 = BinaryTreeUtils.mustFindNode(root, key1);
    BstNode<Integer> node2 = BinaryTreeUtils.mustFindNode(root, key2);

    timer.start();
    BstNode<Integer> result = findLCA(root, node1, node2);
    timer.stop();

    if (result == null)
      throw new TestFailureException("Result can't be null");
    return result.data;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
