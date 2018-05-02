package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.List;

public class TreeFromPreorderWithNull {

  // Global variable, tracks current subtree.
  private static Integer subtreeIdx;

  public static BinaryTreeNode<Integer>
  reconstructPreorder(List<Integer> preorder) {

    subtreeIdx = 0;
    return reconstructPreorderSubtree(preorder);
  }

  // Reconstructs the subtree that is rooted at subtreeIdx.
  private static BinaryTreeNode<Integer>
  reconstructPreorderSubtree(List<Integer> preorder) {
    Integer subtreeKey = preorder.get(subtreeIdx);
    ++subtreeIdx;
    if (subtreeKey == null) {
      return null;
    }
    // Note that reconstructPreorderSubtree updates subtreeIdx. So the order of
    // following two calls are critical.
    BinaryTreeNode<Integer> leftSubtree = reconstructPreorderSubtree(preorder);
    BinaryTreeNode<Integer> rightSubtree = reconstructPreorderSubtree(preorder);
    return new BinaryTreeNode<>(subtreeKey, leftSubtree, rightSubtree);
  }

  @EpiTest(testDataFile = "tree_from_preorder_with_null.tsv")
  public static BinaryTreeNode<Integer>
  reconstructPreorderWrapper(TimedExecutor executor, List<String> strings)
      throws Exception {
    List<Integer> ints = new ArrayList<>();
    for (String s : strings) {
      if (s.equals("null")) {
        ints.add(null);
      } else {
        ints.add(Integer.parseInt(s));
      }
    }

    return executor.run(() -> reconstructPreorder(ints));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreeFromPreorderWithNull.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
