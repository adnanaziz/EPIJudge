package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.EpiTestExpectedType;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.function.BiPredicate;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class KClosestStars {
  @EpiUserType(ctorParams = {double.class, double.class, double.class})

  public static class Star implements Comparable<Star> {
    private double x, y, z;

    public Star(double x, double y, double z) {
      this.x = x;
      this.y = y;
      this.z = z;
    }

    public double distance() { return Math.sqrt(x * x + y * y + z * z); }

    @Override
    public int compareTo(Star that) {
      return Double.compare(this.distance(), that.distance());
    }

    @Override
    public String toString() {
      return String.valueOf(distance());
    }
  }

  public static List<Star> findClosestKStars(Iterator<Star> stars, int k) {

    // maxHeap to store the closest k stars seen so far.
    PriorityQueue<Star> maxHeap =
        new PriorityQueue<>(k, Collections.reverseOrder());
    while (stars.hasNext()) {
      // Add each star to the max-heap. If the max-heap size exceeds k, remove
      // the maximum element from the max-heap.
      Star star = stars.next();
      maxHeap.add(star);
      if (maxHeap.size() == k + 1) {
        maxHeap.remove();
      }
    }

    // Iteratively extract from the max-heap, which yields the stars sorted
    // according from furthest to closest.
    return Stream.generate(maxHeap::remove)
        .limit(maxHeap.size())
        .collect(Collectors.toList());
  }

  @EpiTest(testDataFile = "k_closest_stars.tsv")
  public static List<Star> findClosestKStarsWrapper(List<Star> stars, int k) {
    return findClosestKStars(stars.iterator(), k);
  }

  @EpiTestExpectedType public static List<Double> expectedType;

  @EpiTestComparator
  public static boolean comp(List<Double> expected, List<Star> result) {
    if (expected.size() != result.size()) {
      return false;
    }
    Collections.sort(result);
    for (int i = 0; i < result.size(); i++) {
      if (result.get(i).distance() != expected.get(i)) {
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "KClosestStars.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
