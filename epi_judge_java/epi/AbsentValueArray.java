package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class AbsentValueArray {

  @EpiTest(testfile = "absent_value_array.tsv")
  public static int findMissingElement(Iterable<Integer> stream) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
