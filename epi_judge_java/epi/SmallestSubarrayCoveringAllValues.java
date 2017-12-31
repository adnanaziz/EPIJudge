package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.List;

public class SmallestSubarrayCoveringAllValues {

  public static class Subarray {
    // Represent subarray by starting and ending indices, inclusive.
    public Integer start;
    public Integer end;

    public Subarray(Integer start, Integer end) {
      this.start = start;
      this.end = end;
    }
  }

  public static Subarray
  findSmallestSequentiallyCoveringSubset(List<String> paragraph,
                                         List<String> keywords) {
    // Implement this placeholder.
    return new Subarray(0, 0);
  }

  @EpiTest(testfile = "subsequence_cover.tsv")
  public static int findSmallestSequentiallyCoveringSubsetWrapper(
      TestTimer timer, List<String> paragraph, List<String> keywords)
      throws TestFailureException {
    timer.start();
    Subarray result =
        findSmallestSequentiallyCoveringSubset(paragraph, keywords);
    timer.stop();

    int kwIdx = 0;
    if (result.start < 0) {
      throw new TestFailureException("Subarray start index is negative");
    }
    int paraIdx = result.start;

    while (kwIdx < keywords.size()) {
      if (paraIdx >= paragraph.size()) {
        throw new TestFailureException(
            "Not all keywords are in the generated subarray");
      }
      if (paraIdx >= paragraph.size()) {
        throw new TestFailureException("Subarray end index exceeds array size");
      }
      if (paragraph.get(paraIdx).equals(keywords.get(kwIdx))) {
        kwIdx++;
      }
      paraIdx++;
    }
    return result.end - result.start + 1;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
