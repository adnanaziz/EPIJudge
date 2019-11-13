package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;
public class RookAttack {

  public static void rookAttack(List<List<Integer>> A) {
    // TODO - you fill in here.
    return;
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
