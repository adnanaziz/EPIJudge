package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Collections;
import java.util.List;

public class MaxWaterTrappable {
  @EpiTest(testDataFile = "max_water_trappable.tsv")

  public static int calculateTrappingWater(List<Integer> heights) {

    // Finds the index with maximum height.
    int maxH = heights.indexOf(Collections.max(heights));
    return trappingWaterTillEnd(heights, 0, maxH, 1) +
        trappingWaterTillEnd(heights, heights.size() - 1, maxH, -1);
  }

  // Assume heights[end] is maximum height.
  private static int trappingWaterTillEnd(List<Integer> heights, int begin,
                                          int end, int step) {
    int sum = 0, highestLevelSeen = Integer.MIN_VALUE;
    for (int i = begin; i != end; i += step) {
      if (heights.get(i) >= highestLevelSeen) {
        highestLevelSeen = heights.get(i);
      } else {
        sum += highestLevelSeen - heights.get(i);
      }
    }
    return sum;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxWaterTrappable.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
