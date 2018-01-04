package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class TreeConnectLeaves {

  public static List<BinaryTreeNode<Integer>>
  createListOfLeaves(BinaryTreeNode<Integer> tree) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "tree_connect_leaves.tsv")
  public static List<Integer>
  createListOfLeavesWrapper(TestTimer timer, BinaryTreeNode<Integer> tree)
      throws TestFailureException {
    timer.start();
    List<BinaryTreeNode<Integer>> result = createListOfLeaves(tree);
    timer.stop();

    if (result.stream().anyMatch(x -> x == null || x.data == null)) {
      throw new TestFailureException("Result can't contain null");
    }

    List<Integer> extractedRes = new ArrayList<>();
    for (BinaryTreeNode<Integer> x : result) {
      extractedRes.add(x.data);
    }
    return extractedRes;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
