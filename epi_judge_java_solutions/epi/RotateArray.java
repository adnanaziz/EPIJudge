package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RotateArray {

  public static void rotateArray(int rotateAmount, List<Integer> A) {

    rotateAmount %= A.size();
    reverse(0, A.size(), A);
    reverse(0, rotateAmount, A);
    reverse(rotateAmount, A.size(), A);
  }

  private static void reverse(int begin, int end, List<Integer> A) {
    for (int i = begin, j = end - 1; i < j; ++i, --j) {
      Collections.swap(A, i, j);
    }
  }

  @EpiTest(testDataFile = "rotate_array.tsv")
  public static List<Integer>
  rotateArrayWrapper(TimedExecutor executor, List<Integer> A, int rotateAmount)
      throws Exception {
    List<Integer> aCopy = new ArrayList<>(A);

    executor.run(() -> rotateArray(rotateAmount, aCopy));
    return aCopy;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RotateArray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
