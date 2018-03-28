package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class TreeLevelOrder {
  @EpiTest(testfile = "tree_level_order.tsv")

  public static List<List<Integer>>
  binaryTreeDepthOrder(BinaryTreeNode<Integer> tree) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
