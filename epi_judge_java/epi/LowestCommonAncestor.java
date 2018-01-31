package epi;

import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

public class LowestCommonAncestor {

  public static BinaryTreeNode<Integer> LCA(BinaryTreeNode<Integer> tree,
                                            BinaryTreeNode<Integer> node0,
                                            BinaryTreeNode<Integer> node1) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "lowest_common_ancestor.tsv")
  public static int lcaWrapper(TestTimer timer, BinaryTreeNode<Integer> tree,
                               Integer node0, int node1)
      throws TestFailureException {
    timer.start();
    BinaryTreeNode<Integer> result =
        LCA(tree, BinaryTreeUtils.mustFindNode(tree, node0),
            BinaryTreeUtils.mustFindNode(tree, node1));
    timer.stop();

    if (result == null) {
      throw new TestFailureException("Result can not be null");
    }
    return result.data;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
