package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.Iterator;
import java.util.List;

public class SunsetView {

  public static List<Integer>
  examineBuildingsWithSunset(Iterator<Integer> sequence) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "sunset_view.tsv")
  public static List<Integer>
  examineBuildingsWithSunsetWrapper(List<Integer> sequence) {
    return examineBuildingsWithSunset(sequence.iterator());
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
