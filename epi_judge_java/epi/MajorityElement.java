package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.Iterator;
import java.util.List;

public class MajorityElement {

  public static String majoritySearch(Iterator<String> inputStream) {
    // Implement this placeholder.
    return "";
  }

  @EpiTest(testfile = "majority_element.tsv")
  public static String majoritySearchWrapper(List<String> inputStream) {
    return majoritySearch(inputStream.iterator());
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
