package epi;

import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

public class SuccessorInTree {

  public static BinaryTree<Integer> findSuccessor(BinaryTree<Integer> node) {

    BinaryTree<Integer> iter = node;
    if (iter.right != null) {
      // Find the leftmost element in node's right subtree.
      iter = iter.right;
      while (iter.left != null) {
        iter = iter.left;
      }
      return iter;
    }

    // Find the closest ancestor whose left subtree contains node.
    while (iter.parent != null && iter.parent.right == iter) {
      iter = iter.parent;
    }
    // A return value of null means node does not have successor, i.e., it is
    // the rightmost node in the tree.
    return iter.parent;
  }

  @EpiTest(testDataFile = "successor_in_tree.tsv")
  public static int findSuccessorWrapper(TimedExecutor executor,
                                         BinaryTree<Integer> tree, int nodeIdx)
      throws Exception {
    BinaryTree<Integer> n = BinaryTreeUtils.mustFindNode(tree, nodeIdx);

    BinaryTree<Integer> result = executor.run(() -> findSuccessor(n));

    return result == null ? -1 : result.data;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SuccessorInTree.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
