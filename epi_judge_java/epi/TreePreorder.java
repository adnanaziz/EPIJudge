package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import java.util.List;
public class TreePreorder {
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
