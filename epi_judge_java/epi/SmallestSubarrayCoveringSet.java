package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class SmallestSubarrayCoveringSet {

  // Represent subarray by starting and ending indices, inclusive.
  private static class Subarray {
    public Integer start;
    public Integer end;

    public Subarray(Integer start, Integer end) {
      this.start = start;
      this.end = end;
    }
  }

  public static Subarray findSmallestSubarrayCoveringSet(List<String> paragraph,
                                                         Set<String> keywords) {
    // Implement this placeholder.
    return new Subarray(0, 0);
  }

  @EpiTest(testfile = "smallest_subarray_covering_set.tsv")
  public static int findSmallestSubarrayCoveringSetWrapper(
      TestTimer timer, List<String> paragraph, Set<String> keywords)
      throws TestFailureException {
    Set<String> copy = new HashSet<>(keywords);

    timer.start();
    Subarray result = findSmallestSubarrayCoveringSet(paragraph, keywords);
    timer.stop();

    if (result.start < 0 || result.start >= paragraph.size() ||
        result.end < 0 || result.end >= paragraph.size() ||
        result.start > result.end)
      throw new TestFailureException("Index out of range");

    for (int i = result.start; i <= result.end; i++)
      copy.remove(paragraph.get(i));

    if (!copy.isEmpty())
      throw new TestFailureException("Not all keywords are in the range");

    return result.end - result.start + 1;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
