package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.ArrayList;
import java.util.List;

public class RookAttack {

  public static void rookAttack(List<List<Integer>> A) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "rook_attack.tsv")
  public static List<List<Integer>> rookAttackWrapper(List<List<Integer>> A) {
    List<List<Integer>> aCopy = new ArrayList<>(A);
    rookAttack(aCopy);
    return aCopy;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
