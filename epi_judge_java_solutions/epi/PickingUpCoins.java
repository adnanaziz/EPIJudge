package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PickingUpCoins {
  @EpiTest(testDataFile = "picking_up_coins.tsv")

  public static int pickUpCoins(List<Integer> coins) {

    return computeMaximumRevenueForRange(coins, 0, coins.size() - 1,
                                         new int[coins.size()][coins.size()]);
  }

  private static int
  computeMaximumRevenueForRange(List<Integer> coins, int a, int b,
                                int[][] maximumRevenueForRange) {
    if (a > b) {
      // No coins left.
      return 0;
    }

    if (maximumRevenueForRange[a][b] == 0) {
      int maximumRevenueA =
          coins.get(a) +
          Math.min(computeMaximumRevenueForRange(coins, a + 2, b,
                                                 maximumRevenueForRange),
                   computeMaximumRevenueForRange(coins, a + 1, b - 1,
                                                 maximumRevenueForRange));
      int maximumRevenueB =
          coins.get(b) +
          Math.min(computeMaximumRevenueForRange(coins, a + 1, b - 1,
                                                 maximumRevenueForRange),
                   computeMaximumRevenueForRange(coins, a, b - 2,
                                                 maximumRevenueForRange));
      maximumRevenueForRange[a][b] = Math.max(maximumRevenueA, maximumRevenueB);
    }
    return maximumRevenueForRange[a][b];
  }

  private static int maximumRevenueAlternative(List<Integer> coins) {
    List<Integer> prefixSum = new ArrayList<>();
    coins.stream().reduce(0, (left, right) -> {
      prefixSum.add(left + right);
      return left + right;
    });
    List<List<Integer>> maximumRevenueForRange = new ArrayList<>(coins.size());
    for (int i = 0; i < coins.size(); ++i) {
      maximumRevenueForRange.add(
          new ArrayList<>(Collections.nCopies(coins.size(), -1)));
    }
    return maximumRevenueAlternativeHelper(coins, 0, coins.size() - 1,
                                           prefixSum, maximumRevenueForRange);
  }

  private static int
  maximumRevenueAlternativeHelper(List<Integer> coins, int a, int b,
                                  List<Integer> prefixSum,
                                  List<List<Integer>> maximumRevenueForRange) {
    if (a > b) {
      return 0;
    } else if (a == b) {
      return coins.get(a);
    }

    if (maximumRevenueForRange.get(a).get(b) == -1) {
      maximumRevenueForRange.get(a).set(
          b, Math.max(
                 coins.get(a) + prefixSum.get(b) -
                     (a + 1 > 0 ? prefixSum.get(a) : 0) -
                     maximumRevenueAlternativeHelper(coins, a + 1, b, prefixSum,
                                                     maximumRevenueForRange),
                 coins.get(b) + prefixSum.get(b - 1) -
                     (a > 0 ? prefixSum.get(a - 1) : 0) -
                     maximumRevenueAlternativeHelper(coins, a, b - 1, prefixSum,
                                                     maximumRevenueForRange)));
    }
    return maximumRevenueForRange.get(a).get(b);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PickingUpCoins.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
