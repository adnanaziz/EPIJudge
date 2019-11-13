package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TreeExterior {

  public static List<BinaryTreeNode<Integer>>
  exteriorBinaryTree(BinaryTreeNode<Integer> tree) {

    if (tree == null) {
      return Collections.emptyList();
    }

    List<BinaryTreeNode<Integer>> exterior = new ArrayList<>() {
      { add(tree); }
    };
    leftBoundary(tree.left, exterior);
    leaves(tree.left, exterior);
    leaves(tree.right, exterior);
    rightBoundary(tree.right, exterior);
    return exterior;
  }

  // Computes the nodes from the root to the leftmost leaf.
  private static void leftBoundary(BinaryTreeNode<Integer> subtree,
                                   List<BinaryTreeNode<Integer>> exterior) {
    if (subtree == null || (subtree.left == null && subtree.right == null)) {
      return;
    }
    exterior.add(subtree);
    if (subtree.left != null) {
      leftBoundary(subtree.left, exterior);
    } else {
      leftBoundary(subtree.right, exterior);
    }
  }

  // Computes the nodes from the rightmost leaf to the root.
  private static void rightBoundary(BinaryTreeNode<Integer> subtree,
                                    List<BinaryTreeNode<Integer>> exterior) {
    if (subtree == null || (subtree.left == null && subtree.right == null)) {
      return;
    }
    if (subtree.right != null) {
      rightBoundary(subtree.right, exterior);
    } else {
      rightBoundary(subtree.left, exterior);
    }
    exterior.add(subtree);
  }

  // Compute the leaves in left-to-right order.
  private static void leaves(BinaryTreeNode<Integer> subtree,
                             List<BinaryTreeNode<Integer>> exterior) {
    if (subtree == null) {
      return;
    }
    if (subtree.left == null && subtree.right == null) {
      exterior.add(subtree);
      return;
    }
    leaves(subtree.left, exterior);
    leaves(subtree.right, exterior);
  }

  private static List<Integer> createOutputList(List<BinaryTreeNode<Integer>> L)
      throws TestFailure {
    if (L.contains(null)) {
      throw new TestFailure("Resulting list contains null");
    }
    List<Integer> output = new ArrayList<>();
    for (BinaryTreeNode<Integer> l : L) {
      output.add(l.data);
    }
    return output;
  }

  @EpiTest(testDataFile = "tree_exterior.tsv")
  public static List<Integer>
  exteriorBinaryTreeWrapper(TimedExecutor executor,
                            BinaryTreeNode<Integer> tree) throws Exception {
    List<BinaryTreeNode<Integer>> result =
        executor.run(() -> exteriorBinaryTree(tree));

    return createOutputList(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreeExterior.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
