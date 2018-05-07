package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import java.util.List;
public class TreePostorder {
  @EpiTest(testDataFile = "tree_postorder.tsv")

  // We use stack and previous node pointer to simulate postorder traversal.
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
