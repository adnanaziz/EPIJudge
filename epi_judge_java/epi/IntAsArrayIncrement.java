package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class IntAsArrayIncrement {
  @EpiTest(testfile = "int_as_array_increment.tsv")
  public static List<Integer> plusOne(List<Integer> A) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
