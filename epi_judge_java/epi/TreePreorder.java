package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class TreePreorder {

  private static class NodeAndState {
    public BinaryTreeNode<Integer> node;
    public Boolean nodeProcessed;

    public NodeAndState(BinaryTreeNode<Integer> node, Boolean nodeProcessed) {
      this.node = node;
      this.nodeProcessed = nodeProcessed;
    }
  }

  @EpiTest(testDataFile = "tree_preorder.tsv")
  public static List<Integer> preorderTraversal(BinaryTreeNode<Integer> tree) {
    // TODO - you fill in here.
    return null;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreePreorder.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
