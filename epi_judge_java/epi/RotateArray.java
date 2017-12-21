package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class RotateArray {
  public static void rotateArray(int i, List<Integer> A) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "rotate_array.tsv")
  public static List<Integer> rotateArrayWrapper(List<Integer> A, int k) {
    rotateArray(k, A);
    return A;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
