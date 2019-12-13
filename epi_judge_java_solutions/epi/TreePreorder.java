package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
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

    List<Integer> result = new ArrayList<>();

    Deque<NodeAndState> inProcess = new ArrayDeque<>();
    inProcess.addFirst(new NodeAndState(tree, false));
    while (!inProcess.isEmpty()) {
      NodeAndState nodeAndState = inProcess.removeFirst();
      if (nodeAndState.node != null) {
        if (nodeAndState.nodeProcessed) {
          result.add(nodeAndState.node.data);
        } else {
          inProcess.addFirst(new NodeAndState(nodeAndState.node.right, false));
          inProcess.addFirst(new NodeAndState(nodeAndState.node.left, false));
          inProcess.addFirst(new NodeAndState(nodeAndState.node, true));
        }
      }
    }
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreePreorder.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
