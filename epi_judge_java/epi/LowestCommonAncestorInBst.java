package epi;
import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;
public class LowestCommonAncestorInBst {

  // Input nodes are nonempty and the key at s is less than or equal to that at
  // b.
  public static BstNode<Integer>
  findLca(BstNode<Integer> tree, BstNode<Integer> s, BstNode<Integer> b) {
    // TODO - you fill in here.
    return null;
  }
  @EpiTest(testDataFile = "lowest_common_ancestor_in_bst.tsv")
  public static int lcaWrapper(TimedExecutor executor, BstNode<Integer> tree,
                               Integer key0, Integer key1) throws Exception {
    BstNode<Integer> node0 = BinaryTreeUtils.mustFindNode(tree, key0);
    BstNode<Integer> node1 = BinaryTreeUtils.mustFindNode(tree, key1);

    BstNode<Integer> result = executor.run(() -> findLca(tree, node0, node1));

    if (result == null) {
      throw new TestFailure("Result can't be null");
    }
    return result.data;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LowestCommonAncestorInBst.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
