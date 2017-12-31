package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class TreeExterior {

  public static List<BinaryTreeNode<Integer>>
  exteriorBinaryTree(BinaryTreeNode<Integer> tree) {
    // Implement this placeholder.
    return null;
  }

  private static List<Integer> createOutputList(List<BinaryTreeNode<Integer>> L)
      throws TestFailureException {
    if (L.contains(null)) {
      throw new TestFailureException("Resulting list contains null");
    }
    List<Integer> output = new ArrayList<>();
    for (BinaryTreeNode<Integer> l : L) {
      output.add(l.data);
    }
    return output;
  }

  @EpiTest(testfile = "tree_exterior.tsv")
  public static List<Integer>
  exteriorBinaryTreeWrapper(TestTimer timer, BinaryTreeNode<Integer> tree)
      throws TestFailureException {
    timer.start();
    List<BinaryTreeNode<Integer>> l = exteriorBinaryTree(tree);
    timer.stop();
    return createOutputList(l);
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
