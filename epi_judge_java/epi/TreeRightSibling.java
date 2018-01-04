package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class TreeRightSibling {
  public static class BinaryTreeNode<T> {
    public T data;
    public BinaryTreeNode<T> left, right;
    public BinaryTreeNode<T> next; // Populates this field.

    public BinaryTreeNode(T data) { this.data = data; }
  }

  public static void constructRightSibling(BinaryTreeNode<Integer> tree) {
    // Implement this placeholder.
    return;
  }

  private static BinaryTreeNode<Integer>
  cloneTree(BinaryTree<Integer> original) {
    if (original != null) {
      BinaryTreeNode<Integer> cloned = new BinaryTreeNode<>(original.data);
      cloned.left = cloneTree(original.left);
      cloned.right = cloneTree(original.right);
      return cloned;
    } else
      return null;
  }

  @EpiTest(testfile = "tree_right_sibling.tsv")
  public static List<List<Integer>>
  constructRightSiblingWrapper(TestTimer timer, BinaryTree<Integer> tree) {
    BinaryTreeNode<Integer> cloned = cloneTree(tree);

    timer.start();
    constructRightSibling(cloned);
    timer.stop();

    List<List<Integer>> result = new ArrayList<>();
    BinaryTreeNode<Integer> levelStart = cloned;
    while (levelStart != null) {
      List<Integer> level = new ArrayList<>();
      BinaryTreeNode<Integer> levelIt = levelStart;
      while (levelIt != null) {
        level.add(levelIt.data);
        levelIt = levelIt.next;
      }
      result.add(level);
      levelStart = levelStart.left;
    }
    return result;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
