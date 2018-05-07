package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MaxSafeHeight {
  @EpiTest(testDataFile = "max_safe_height.tsv")

  public static int getHeight(int cases, int drops) {

    List<List<Integer>> F = new ArrayList<>(cases + 1);
    for (int i = 0; i < cases + 1; ++i) {
      F.add(new ArrayList<>(Collections.nCopies(drops + 1, -1)));
    }
    return getHeightHelper(cases, drops, F);
  }

  private static int getHeightHelper(int cases, int drops,
                                     List<List<Integer>> F) {
    if (cases == 0 || drops == 0) {
      return 0;
    } else if (cases == 1) {
      return drops;
    }
    if (F.get(cases).get(drops) == -1) {
      F.get(cases).set(drops, getHeightHelper(cases, drops - 1, F) +
                                  getHeightHelper(cases - 1, drops - 1, F) + 1);
    }
    return F.get(cases).get(drops);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxSafeHeight.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
