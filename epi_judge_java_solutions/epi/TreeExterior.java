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
    List<BinaryTreeNode<Integer>> exterior = new ArrayList<>();
    if (tree != null) {
      exterior.add(tree);
      leftBoundaryAndLeaves(tree.left, true, exterior);
      rightBoundaryAndLeaves(tree.right, true, exterior);
    }
    return exterior;
  }

  // Computes the nodes from the root to the leftmost leaf followed by all the
  // leaves in subtreeRoot.
  private static void
  leftBoundaryAndLeaves(BinaryTreeNode<Integer> subtreeRoot, boolean isBoundary,
                        List<BinaryTreeNode<Integer>> exterior) {
    if (subtreeRoot != null) {
      if (isBoundary || isLeaf(subtreeRoot)) {
        exterior.add(subtreeRoot);
      }
      leftBoundaryAndLeaves(subtreeRoot.left, isBoundary, exterior);
      leftBoundaryAndLeaves(subtreeRoot.right,
                            isBoundary && subtreeRoot.left == null, exterior);
    }
  }

  // Computes the leaves in left-to-right order followed by the rightmost leaf
  // to the root path in subtreeRoot.
  private static void
  rightBoundaryAndLeaves(BinaryTreeNode<Integer> subtreeRoot,
                         boolean isBoundary,
                         List<BinaryTreeNode<Integer>> exterior) {
    if (subtreeRoot != null) {
      rightBoundaryAndLeaves(subtreeRoot.left,
                             isBoundary && subtreeRoot.right == null, exterior);
      rightBoundaryAndLeaves(subtreeRoot.right, isBoundary, exterior);
      if (isBoundary || isLeaf(subtreeRoot)) {
        exterior.add(subtreeRoot);
      }
    }
  }

  private static boolean isLeaf(BinaryTreeNode<Integer> node) {
    return node.left == null && node.right == null;
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

  @EpiTest(testfile = "tree_exterior.tsv")
  public static List<Integer>
  exteriorBinaryTreeWrapper(TimedExecutor executor,
                            BinaryTreeNode<Integer> tree) throws Exception {
    List<BinaryTreeNode<Integer>> l =
        executor.run(() -> exteriorBinaryTree(tree));
    return createOutputList(l);
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
