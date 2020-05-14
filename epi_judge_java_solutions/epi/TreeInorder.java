package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class TreeInorder {

  private static class NodeAndState {
    public BinaryTreeNode<Integer> node;
    public Boolean leftSubtreeTraversed;

    public NodeAndState(BinaryTreeNode<Integer> node,
                        Boolean leftSubtreeTraversed) {
      this.node = node;
      this.leftSubtreeTraversed = leftSubtreeTraversed;
    }
  }

  @EpiTest(testDataFile = "tree_inorder.tsv")
  public static List<Integer> inorderTraversal(BinaryTreeNode<Integer> tree) {

    List<Integer> result = new ArrayList<>();

    Deque<NodeAndState> inProcess = new ArrayDeque<>();
    inProcess.addFirst(new NodeAndState(tree, /*leftSubtreeTraversed=*/false));
    while (!inProcess.isEmpty()) {
      NodeAndState nodeAndState = inProcess.removeFirst();
      if (nodeAndState.node != null) {
        if (nodeAndState.leftSubtreeTraversed) {
          result.add(nodeAndState.node.data);
        } else {
          inProcess.addFirst(new NodeAndState(nodeAndState.node.right,
                                              /*leftSubtreeTraversed=*/false));
          inProcess.addFirst(new NodeAndState(nodeAndState.node,
                                              /*leftSubtreeTraversed=*/true));
          inProcess.addFirst(new NodeAndState(nodeAndState.node.left,
                                              /*leftSubtreeTraversed=*/false));
        }
      }
    }
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreeInorder.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
