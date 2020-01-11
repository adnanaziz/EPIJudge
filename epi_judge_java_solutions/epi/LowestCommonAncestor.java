package epi;

import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

public class LowestCommonAncestor {

  private static class Status {
    public int numTargetNodes;
    public BinaryTreeNode<Integer> ancestor;

    public Status(int numTargetNodes, BinaryTreeNode<Integer> node) {
      this.numTargetNodes = numTargetNodes;
      this.ancestor = node;
    }
  }

  public static BinaryTreeNode<Integer> lca(BinaryTreeNode<Integer> tree,
                                            BinaryTreeNode<Integer> node0,
                                            BinaryTreeNode<Integer> node1) {

    return lcaHelper(tree, node0, node1).ancestor;
  }

  // Returns an object consisting of an int and a node. The int field is
  // 0, 1, or 2 depending on how many of {node0, node1} are present in
  // the tree. If both are present in the tree, when ancestor is
  // assigned to a non-null value, it is the LCA.
  private static Status lcaHelper(BinaryTreeNode<Integer> tree,
                                  BinaryTreeNode<Integer> node0,
                                  BinaryTreeNode<Integer> node1) {
    if (tree == null) {
      return new Status(/*numTargetNodes=*/0, /*ancestor=*/null);
    }

    Status leftResult = lcaHelper(tree.left, node0, node1);
    if (leftResult.numTargetNodes == 2) {
      // Found both nodes in the left subtree.
      return leftResult;
    }
    Status rightResult = lcaHelper(tree.right, node0, node1);
    if (rightResult.numTargetNodes == 2) {
      // Found both nodes in the right subtree.
      return rightResult;
    }
    int numTargetNodes = leftResult.numTargetNodes +
                         rightResult.numTargetNodes + (tree == node0 ? 1 : 0) +
                         (tree == node1 ? 1 : 0);
    return new Status(numTargetNodes, numTargetNodes == 2 ? tree : null);
  }

  @EpiTest(testDataFile = "lowest_common_ancestor.tsv")
  public static int lcaWrapper(TimedExecutor executor,
                               BinaryTreeNode<Integer> tree, Integer key0,
                               Integer key1) throws Exception {
    BinaryTreeNode<Integer> node0 = BinaryTreeUtils.mustFindNode(tree, key0);
    BinaryTreeNode<Integer> node1 = BinaryTreeUtils.mustFindNode(tree, key1);

    BinaryTreeNode<Integer> result =
        executor.run(() -> lca(tree, node0, node1));

    if (result == null) {
      throw new TestFailure("Result can not be null");
    }
    return result.data;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LowestCommonAncestor.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
