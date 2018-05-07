package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.List;

public class MinimumPointsCoveringIntervals {
  @EpiUserType(ctorParams = {int.class, int.class})

  public static class Interval {
    public int left, right;

    public Interval(int l, int r) {
      this.left = l;
      this.right = r;
    }
  }

  @EpiTest(testDataFile = "minimum_points_covering_intervals.tsv")

  public static Integer findMinimumVisits(List<Interval> intervals) {

    // Sort intervals based on the right endpoints.
    intervals.sort((i1, i2) -> Integer.compare(i1.right, i2.right));
    Integer lastVisitTime = Integer.MIN_VALUE;
    Integer numVisits = 0;
    for (Interval interval : intervals) {
      if (interval.left > lastVisitTime) {
        // The current right endpoint, lastVisitTime, will not cover any more
        // intervals.
        lastVisitTime = interval.right;
        ++numVisits;
      }
    }
    return numVisits;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MinimumPointsCoveringIntervals.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
