package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class TreeInorder {
  @EpiTest(testDataFile = "tree_inorder.tsv")

  public static List<Integer> inorderTraversal(BinaryTreeNode<Integer> tree) {

    Deque<BinaryTreeNode<Integer>> s = new ArrayDeque<>();
    BinaryTreeNode<Integer> curr = tree;
    List<Integer> result = new ArrayList<>();

    while (!s.isEmpty() || curr != null) {
      if (curr != null) {
        s.addFirst(curr);
        // Going left.
        curr = curr.left;
      } else {
        // Going up.
        curr = s.removeFirst();
        result.add(curr.data);
        // Going right.
        curr = curr.right;
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
