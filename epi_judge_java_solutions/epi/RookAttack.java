package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RookAttack {

  public static void rookAttack(List<List<Integer>> A) {

    int m = A.size(), n = A.get(0).size();
    boolean hasFirstRowZero = A.get(0).contains(0);
    boolean hasFirstColumnZero = A.stream().anyMatch(row -> row.get(0) == 0);

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (A.get(i).get(j) == 0) {
          A.get(i).set(0, 0);
          A.get(0).set(j, 0);
        }
      }
    }

    for (int i = 1; i < m; ++i) {
      if (A.get(i).get(0) == 0) {
        Collections.fill(A.get(i), 0);
      }
    }

    for (int j = 1; j < n; ++j) {
      if (A.get(0).get(j) == 0) {
        final int idx = j;
        A.stream().forEach(row -> row.set(idx, 0));
      }
    }

    if (hasFirstRowZero) {
      Collections.fill(A.get(0), 0);
    }
    if (hasFirstColumnZero) {
      A.stream().forEach(row -> row.set(0, 0));
    }
  }

  @EpiTest(testDataFile = "rook_attack.tsv")
  public static List<List<Integer>> rookAttackWrapper(List<List<Integer>> A) {
    List<List<Integer>> aCopy = new ArrayList<>(A);
    rookAttack(aCopy);
    return aCopy;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RookAttack.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
