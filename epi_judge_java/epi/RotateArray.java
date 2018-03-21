package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.List;

public class RotateArray {

  public static void rotateArray(int rotateAmount, List<Integer> A) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "rotate_array.tsv")
  public static List<Integer>
  rotateArrayWrapper(TimedExecutor executor, List<Integer> A, int rotateAmount)
      throws Exception {
    List<Integer> aCopy = new ArrayList<>(A);

    executor.run(() -> rotateArray(rotateAmount, aCopy));
    return aCopy;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
