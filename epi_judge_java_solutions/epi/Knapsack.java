package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.Arrays;
import java.util.List;

public class Knapsack {
  @EpiUserType(ctorParams = {Integer.class, Integer.class})

  public static class Item {
    public Integer weight;
    public Integer value;

    public Item(Integer weight, Integer value) {
      this.weight = weight;
      this.value = value;
    }
  }

  @EpiTest(testDataFile = "knapsack.tsv")

  public static int optimumSubjectToCapacity(List<Item> items, int capacity) {

    // V[i][j] holds the optimum value when we choose from
    // items.subList(0, i + 1) and have a capacity of j.
    int[][] V = new int[items.size()][capacity + 1];
    for (int[] v : V) {
      Arrays.fill(v, -1);
    }
    return optimumSubjectToItemAndCapacity(items, items.size() - 1, capacity,
                                           V);
  }

  // Returns the optimum value when we choose from items.subList(0, k + 1) and
  // have a capacity of availableCapacity.
  private static int optimumSubjectToItemAndCapacity(List<Item> items, int k,
                                                     int availableCapacity,
                                                     int[][] V) {
    if (k < 0) {
      // No items can be chosen.
      return 0;
    }

    if (V[k][availableCapacity] == -1) {
      int withoutCurrItem =
          optimumSubjectToItemAndCapacity(items, k - 1, availableCapacity, V);
      int withCurrItem =
          availableCapacity < items.get(k).weight
              ? 0
              : items.get(k).value +
                    optimumSubjectToItemAndCapacity(
                        items, k - 1, availableCapacity - items.get(k).weight,
                        V);
      V[k][availableCapacity] = Math.max(withoutCurrItem, withCurrItem);
    }
    return V[k][availableCapacity];
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Knapsack.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
