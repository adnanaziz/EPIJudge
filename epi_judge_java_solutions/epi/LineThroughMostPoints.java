package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.math.BigInteger;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LineThroughMostPoints {
  @EpiUserType(ctorParams = {int.class, int.class})

  public static class Point {
    public int x, y;

    public Point(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  @EpiTest(testDataFile = "line_through_most_points.tsv")

  public static int findLineWithMostPoints(List<Point> points) {

    int result = 0;
    for (int i = 0; i < points.size(); ++i) {
      Map<Integer, Map<Integer, Integer>> slopeTable = new HashMap<>();
      int overlapPoints = 1;
      for (int j = i + 1; j < points.size(); ++j) {
        if (points.get(i).x == points.get(j).x &&
            points.get(i).y == points.get(j).y) {
          ++overlapPoints;
        } else {
          int xDiff = points.get(i).x - points.get(j).x,
              yDiff = points.get(i).y - points.get(j).y;
          if (xDiff == 0) {
            // A vertical line with slope 1/0.
            yDiff = 1;
          } else {
            int gcd = BigInteger.valueOf(xDiff)
                          .gcd(BigInteger.valueOf(yDiff))
                          .intValue();
            xDiff /= gcd;
            yDiff /= gcd;
            if (xDiff < 0) {
              xDiff = -xDiff;
              yDiff = -yDiff;
            }
          }
          slopeTable.putIfAbsent(xDiff, new HashMap<>());
          slopeTable.get(xDiff).put(
              yDiff, slopeTable.get(xDiff).getOrDefault(yDiff, 0) + 1);
        }
      }
      result = Math.max(
          result, overlapPoints +
                      (slopeTable.isEmpty()
                           ? 0
                           : Collections.max(
                                 Collections
                                     .max(slopeTable.values(),
                                          Comparator.comparingInt(
                                              m -> Collections.max(m.values())))
                                     .values())));
    }
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LineThroughMostPoints.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
