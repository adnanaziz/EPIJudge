package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class RotateArray {

  public static void rotateArray(int rotateAmount, List<Integer> A) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "rotate_array.tsv")
  public static List<Integer>
  rotateArrayWrapper(TestTimer timer, List<Integer> A, int rotateAmount) {
    List<Integer> aCopy = new ArrayList<>(A);
    timer.start();
    rotateArray(rotateAmount, aCopy);
    timer.stop();
    return aCopy;
  }

  public static void main(String[] args) {
    GenericTest.runFromAnnotations(
        args, new Object() {}.getClass().getEnclosingClass());
  }
}
