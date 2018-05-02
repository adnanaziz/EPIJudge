package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List;

public class TreePostorder {
  @EpiTest(testDataFile = "tree_postorder.tsv")

  // We use stack and previous node pointer to simulate postorder traversal.
  public static List<Integer> postorderTraversal(BinaryTreeNode<Integer> tree) {

    if (tree == null) { // Empty tree.
      return Collections.emptyList();
    }

    Deque<BinaryTreeNode<Integer>> path = new ArrayDeque<>();
    BinaryTreeNode<Integer> prev = null;
    path.addFirst(tree);
    List<Integer> postorderSequence = new ArrayList<>();
    while (!path.isEmpty()) {
      BinaryTreeNode<Integer> curr = path.peekFirst();
      if (prev == null || prev.left == curr || prev.right == curr) {
        // We came down to curr from prev.
        if (curr.left != null) { // Traverse left.
          path.addFirst(curr.left);
        } else if (curr.right != null) { // Traverse right.
          path.addFirst(curr.right);
        } else { // Leaf node, so visit current node.
          postorderSequence.add(curr.data);
          path.removeFirst();
        }
      } else if (curr.left == prev) {
        // Done with left, so now traverse right.
        if (curr.right != null) { // Visit right.
          path.addFirst(curr.right);
        } else { // // No right child, so visit curr.
          postorderSequence.add(curr.data);
          path.removeFirst();
        }
      } else {
        // Finished traversing left and right, so visit curr.
        postorderSequence.add(curr.data);
        path.removeFirst();
      }
      prev = curr;
    }
    return postorderSequence;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreePostorder.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
