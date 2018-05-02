package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;

public class IntervalAdd {
  @EpiUserType(ctorParams = {int.class, int.class})

  public static class Interval {
    public int left, right;

    public Interval(int l, int r) {
      this.left = l;
      this.right = r;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      Interval interval = (Interval)o;

      if (left != interval.left) {
        return false;
      }
      return right == interval.right;
    }

    @Override
    public String toString() {
      return "[" + left + ", " + right + "]";
    }
  }

  @EpiTest(testDataFile = "interval_add.tsv")

  public static List<Interval> addInterval(List<Interval> disjointIntervals,
                                           Interval newInterval) {

    int i = 0;
    List<Interval> result = new ArrayList<>();
    // Processes intervals in disjointIntervals which come before newInterval.
    while (i < disjointIntervals.size() &&
           newInterval.left > disjointIntervals.get(i).right) {
      result.add(disjointIntervals.get(i++));
    }

    // Processes intervals in disjointIntervals which overlap with newInterval.
    while (i < disjointIntervals.size() &&
           newInterval.right >= disjointIntervals.get(i).left) {
      // If [a, b] and [c, d] overlap, their union is [min(a, c),max(b, d)].
      newInterval = new Interval(
          Math.min(newInterval.left, disjointIntervals.get(i).left),
          Math.max(newInterval.right, disjointIntervals.get(i).right));
      ++i;
    }
    result.add(newInterval);

    // Processes intervals in disjointIntervals which come after newInterval.
    result.addAll(disjointIntervals.subList(i, disjointIntervals.size()));
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IntervalAdd.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
