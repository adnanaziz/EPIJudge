package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.List;

public class AlternatingArray {
  public static void rearrange(List<Integer> A) {
    // Implement this placeholder.
    return;
  }

  private static void checkAnswer(List<Integer> A) throws TestFailureException {
    for (int i = 0; i < A.size(); ++i) {
      if ((i % 2) != 0) {
        if (A.get(i) < A.get(i - 1)) {
          throw new TestFailureException("");
        }
        if (i < A.size() - 1) {
          if (A.get(i) < A.get(i + 1)) {
            throw new TestFailureException("");
          }
        }
      } else {
        if (i > 0) {
          if (A.get(i - 1) < A.get(i)) {
            throw new TestFailureException("");
          }
        }
        if (i < A.size() - 1) {
          if (A.get(i + 1) < A.get(i)) {
            throw new TestFailureException("");
          }
        }
      }
    }
  }

  @EpiTest(testfile = "alternating_array.tsv")
  public static void rearrangeWrapper(TestTimer timer, List<Integer> A)
      throws TestFailureException {
    timer.start();
    rearrange(A);
    timer.stop();

    checkAnswer(A);
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
