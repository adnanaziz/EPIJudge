package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IsTreeBalanced {

  private static class BalanceStatusWithHeight {
    public boolean balanced;
    public int height;

    public BalanceStatusWithHeight(boolean balanced, int height) {
      this.balanced = balanced;
      this.height = height;
    }
  }

  @EpiTest(testDataFile = "is_tree_balanced.tsv")

  public static boolean isBalanced(BinaryTreeNode<Integer> tree) {

    return checkBalanced(tree).balanced;
  }

  private static BalanceStatusWithHeight
  checkBalanced(BinaryTreeNode<Integer> tree) {
    if (tree == null) {
      return new BalanceStatusWithHeight(/*balanced=*/true, /*height=*/-1);
    }

    BalanceStatusWithHeight leftResult = checkBalanced(tree.left);
    if (!leftResult.balanced) {
      return leftResult;
    }
    BalanceStatusWithHeight rightResult = checkBalanced(tree.right);
    if (!rightResult.balanced) {
      return rightResult;
    }

    boolean isBalanced = Math.abs(leftResult.height - rightResult.height) <= 1;
    int height = Math.max(leftResult.height, rightResult.height) + 1;
    return new BalanceStatusWithHeight(isBalanced, height);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IsTreeBalanced.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
