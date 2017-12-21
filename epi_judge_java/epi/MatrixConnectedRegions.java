package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class MatrixConnectedRegions {
  public static void flipColor(int x, int y, List<List<Boolean>> A) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "painting.tsv")
  public static List<List<Integer>> flipColorWrapper(
      TestTimer timer, int x, int y, List<List<Integer>> A) {
    List<List<Boolean>> B = new ArrayList<>();
    for (int i = 0; i < A.size(); i++) {
      B.add(new ArrayList<>());
      for (int j = 0; j < A.get(i).size(); j++) {
        B.get(i).add(A.get(i).get(j) == 1);
      }
    }

    timer.start();
    flipColor(x, y, B);
    timer.stop();

    A = new ArrayList<>();
    for (int i = 0; i < B.size(); i++) {
      A.add(new ArrayList<>());
      for (int j = 0; j < B.get(i).size(); j++) {
        A.get(i).add(B.get(i).get(j) ? 1 : 0);
      }
    }

    return A;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
