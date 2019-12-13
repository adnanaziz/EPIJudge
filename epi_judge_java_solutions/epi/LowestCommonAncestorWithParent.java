package epi;

import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

public class LowestCommonAncestorWithParent {

  public static BinaryTree<Integer> lca(BinaryTree<Integer> node0,
                                        BinaryTree<Integer> node1) {

    int depth0 = getDepth(node0), depth1 = getDepth(node1);
    // Makes node0 as the deeper node in order to simplify the code.
    if (depth1 > depth0) {
      BinaryTree<Integer> temp = node0;
      node0 = node1;
      node1 = temp;
    }
    // Ascends from the deeper node.
    int depthDiff = Math.abs(depth0 - depth1);
    while (depthDiff-- > 0) {
      node0 = node0.parent;
    }

    // Now ascends both nodes until we reach the LCA.
    while (node0 != node1) {
      node0 = node0.parent;
      node1 = node1.parent;
    }
    return node0;
  }

  private static int getDepth(BinaryTree<Integer> node) {
    int depth = 0;
    while (node.parent != null) {
      ++depth;
      node = node.parent;
    }
    return depth;
  }

  @EpiTest(testDataFile = "lowest_common_ancestor.tsv")
  public static int lcaWrapper(TimedExecutor executor, BinaryTree<Integer> tree,
                               Integer key0, Integer key1) throws Exception {
    BinaryTree<Integer> node0 = BinaryTreeUtils.mustFindNode(tree, key0);
    BinaryTree<Integer> node1 = BinaryTreeUtils.mustFindNode(tree, key1);

    BinaryTree<Integer> result = executor.run(() -> lca(node0, node1));

    if (result == null) {
      throw new TestFailure("Result can not be null");
    }
    return result.data;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LowestCommonAncestorWithParent.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
