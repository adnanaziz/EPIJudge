package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class TreePostorder {

  private static class NodeAndState {
    public BinaryTreeNode<Integer> node;
    public Boolean subtreesTraversed;

    public NodeAndState(BinaryTreeNode<Integer> node,
                        Boolean subtreesTraversed) {
      this.node = node;
      this.subtreesTraversed = subtreesTraversed;
    }
  }

  @EpiTest(testDataFile = "tree_postorder.tsv")
  public static List<Integer> postorderTraversal(BinaryTreeNode<Integer> tree) {
    // TODO - you fill in here.
    return null;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreePostorder.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
