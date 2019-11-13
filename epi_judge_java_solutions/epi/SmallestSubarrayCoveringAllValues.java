package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

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

    // Maps each keyword to its index in the keywords array.
    Map<String, Integer> keywordToIdx = new HashMap<>();

    // Since keywords are uniquely identified by their indices in keywords
    // array, we can use those indices as keys to lookup in a vector.
    List<Integer> latestOccurrence = new ArrayList<>(keywords.size());

    // For each keyword (identified by its index in keywords array), stores the
    // length of the shortest subarray ending at the most recent occurrence of
    // that keyword that sequentially cover all keywords up to that keyword.
    List<Integer> shortestSubarrayLength = new ArrayList<>(keywords.size());

    // Initializes latestOccurrence, shortestSubarrayLength, and keywordToIdx.
    for (int i = 0; i < keywords.size(); ++i) {
      latestOccurrence.add(-1);
      shortestSubarrayLength.add(Integer.MAX_VALUE);
      keywordToIdx.put(keywords.get(i), i);
    }

    int shortestDistance = Integer.MAX_VALUE;
    Subarray result = new Subarray(-1, -1);
    for (int i = 0; i < paragraph.size(); ++i) {
      Integer keywordIdx = keywordToIdx.get(paragraph.get(i));
      if (keywordIdx != null) {
        if (keywordIdx == 0) { // First keyword.
          shortestSubarrayLength.set(0, 1);
        } else if (shortestSubarrayLength.get(keywordIdx - 1) !=
                   Integer.MAX_VALUE) {
          int distanceToPreviousKeyword =
              i - latestOccurrence.get(keywordIdx - 1);
          shortestSubarrayLength.set(
              keywordIdx, distanceToPreviousKeyword +
                              shortestSubarrayLength.get(keywordIdx - 1));
        }
        latestOccurrence.set(keywordIdx, i);

        // Last keyword, look for improved subarray.
        if (keywordIdx == keywords.size() - 1 &&
            shortestSubarrayLength.get(shortestSubarrayLength.size() - 1) <
                shortestDistance) {
          shortestDistance =
              shortestSubarrayLength.get(shortestSubarrayLength.size() - 1);
          result.start =
              i -
              shortestSubarrayLength.get(shortestSubarrayLength.size() - 1) + 1;
          result.end = i;
        }
      }
    }
    return result;
  }

  @EpiTest(testDataFile = "smallest_subarray_covering_all_values.tsv")
  public static int findSmallestSequentiallyCoveringSubsetWrapper(
      TimedExecutor executor, List<String> paragraph, List<String> keywords)
      throws Exception {
    Subarray result = executor.run(
        () -> findSmallestSequentiallyCoveringSubset(paragraph, keywords));

    int kwIdx = 0;
    if (result.start < 0) {
      throw new TestFailure("Subarray start index is negative");
    }
    int paraIdx = result.start;

    while (kwIdx < keywords.size()) {
      if (paraIdx >= paragraph.size()) {
        throw new TestFailure("Not all keywords are in the generated subarray");
      }
      if (paraIdx >= paragraph.size()) {
        throw new TestFailure("Subarray end index exceeds array size");
      }
      if (paragraph.get(paraIdx).equals(keywords.get(kwIdx))) {
        kwIdx++;
      }
      paraIdx++;
    }
    return result.end - result.start + 1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SmallestSubarrayCoveringAllValues.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
