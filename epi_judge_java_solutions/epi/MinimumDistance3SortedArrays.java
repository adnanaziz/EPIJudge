package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;
import java.util.NavigableSet;
import java.util.TreeSet;

public class MinimumDistance3SortedArrays {

  public static class ArrayData implements Comparable<ArrayData> {
    public int val;
    public int idx;

    public ArrayData(int idx, int val) {
      this.val = val;
      this.idx = idx;
    }

    @Override
    public int compareTo(ArrayData o) {
      int result = Integer.compare(val, o.val);
      if (result == 0) {
        result = Integer.compare(idx, o.idx);
      }
      return result;
    }
  }

  @EpiTest(testDataFile = "minimum_distance_3_sorted_arrays.tsv")

  public static int
  findMinDistanceSortedArrays(List<List<Integer>> sortedArrays) {

    // Indices into each of the arrays.
    List<Integer> heads = new ArrayList<>(sortedArrays.size());
    for (List<Integer> arr : sortedArrays) {
      heads.add(0);
    }
    int result = Integer.MAX_VALUE;
    NavigableSet<ArrayData> currentHeads = new TreeSet<>();

    // Adds the minimum element of each array in to currentHeads.
    for (int i = 0; i < sortedArrays.size(); ++i) {
      currentHeads.add(new ArrayData(i, sortedArrays.get(i).get(heads.get(i))));
    }

    while (true) {
      result =
          Math.min(result, currentHeads.last().val - currentHeads.first().val);
      int idxNextMin = currentHeads.first().idx;
      // Return if some array has no remaining elements.
      heads.set(idxNextMin, heads.get(idxNextMin) + 1);
      if (heads.get(idxNextMin) >= sortedArrays.get(idxNextMin).size()) {
        return result;
      }
      currentHeads.pollFirst();
      currentHeads.add(new ArrayData(
          idxNextMin, sortedArrays.get(idxNextMin).get(heads.get(idxNextMin))));
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MinimumDistance3SortedArrays.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
