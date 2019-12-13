package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SumRootToLeaf {
  @EpiTest(testDataFile = "sum_root_to_leaf.tsv")

  public static int sumRootToLeaf(BinaryTreeNode<Integer> tree) {

    return sumRootToLeafHelper(tree, /*partialPathSum=*/0);
  }

  private static int sumRootToLeafHelper(BinaryTreeNode<Integer> tree,
                                         int partialPathSum) {
    if (tree == null) {
      return 0;
    }

    partialPathSum = partialPathSum * 2 + tree.data;
    if (tree.left == null && tree.right == null) { // Leaf.
      return partialPathSum;
    }
    // Non-leaf.
    return sumRootToLeafHelper(tree.left, partialPathSum) +
        sumRootToLeafHelper(tree.right, partialPathSum);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SumRootToLeaf.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
