package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IsTreeABst {
  @EpiTest(testDataFile = "is_tree_a_bst.tsv")

  public static boolean isBinaryTreeBST(BinaryTreeNode<Integer> tree) {

    return areKeysInRange(tree, Integer.MIN_VALUE, Integer.MAX_VALUE);
  }

  private static boolean areKeysInRange(BinaryTreeNode<Integer> tree,
                                        Integer lower, Integer upper) {
    if (tree == null) {
      return true;
    } else if (Integer.compare(tree.data, lower) < 0 ||
               Integer.compare(tree.data, upper) > 0) {
      return false;
    }

    return areKeysInRange(tree.left, lower, tree.data) &&
        areKeysInRange(tree.right, tree.data, upper);
  }

  private static BinaryTreeNode<Integer> prev = null;

  private static boolean
  isBinaryTreeBSTAlternative(BinaryTreeNode<Integer> tree) {
    prev = null;
    return inorderTraversal(tree);
  }

  private static boolean inorderTraversal(BinaryTreeNode<Integer> tree) {
    if (tree == null) {
      return true;
    } else if (!inorderTraversal(tree.left)) {
      return false;
    } else if (prev != null && prev.data > tree.data) {
      return false;
    }
    prev = tree;
    return inorderTraversal(tree.right);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IsTreeABst.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
