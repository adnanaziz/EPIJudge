package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class TreeFromPreorderWithNull {

  public static BinaryTreeNode<Integer>
  reconstructPreorder(List<Integer> preorder) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "tree_from_preorder_with_null.tsv")
  public static BinaryTreeNode<Integer>
  reconstructPreorderWrapper(TestTimer timer, List<String> strings) {
    List<Integer> ints = new ArrayList<>();
    for (String s : strings) {
      if (s.equals("null")) {
        ints.add(null);
      } else {
        ints.add(Integer.parseInt(s));
      }
    }
    timer.start();
    BinaryTreeNode<Integer> result = reconstructPreorder(ints);
    timer.stop();
    return result;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
