package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

import java.util.List;

public class SortedArrayRemoveDups {
  // Returns the number of valid entries after deletion.
  public static int deleteDuplicates(List<Integer> A) {
    // Implement this placeholder.
    return 0;
  }

  @EpiTest(testfile = "sorted_array_remove_dups.tsv")
  public static List<Integer> deleteDuplicatesWrapper(TestTimer timer,
                                                      List<Integer> A) {
    timer.start();
    int end = deleteDuplicates(A);
    timer.stop();

    return A.subList(0, end);
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
