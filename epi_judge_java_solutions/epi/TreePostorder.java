package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
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

    List<Integer> result = new ArrayList<>();

    Deque<NodeAndState> inProcess = new ArrayDeque<>();
    inProcess.addFirst(new NodeAndState(tree, false));
    while (!inProcess.isEmpty()) {
      NodeAndState nodeAndState = inProcess.removeFirst();
      if (nodeAndState.node != null) {
        if (nodeAndState.subtreesTraversed) {
          result.add(nodeAndState.node.data);
        } else {
          inProcess.addFirst(new NodeAndState(nodeAndState.node, true));
          inProcess.addFirst(new NodeAndState(nodeAndState.node.right, false));
          inProcess.addFirst(new NodeAndState(nodeAndState.node.left, false));
        }
      }
    }
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreePostorder.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
