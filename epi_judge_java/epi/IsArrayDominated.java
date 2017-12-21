package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.List;
import java.util.stream.Collectors;

public class IsArrayDominated {
  @EpiTest(testfile = "is_array_dominated.tsv")
  public static void validPlacementExistsWrapper(TestTimer timer, List<Integer> h1,
      List<Integer> h2, boolean expected12, boolean expected21) throws TestFailureException {
    Team t1 = new Team(h1);
    Team t2 = new Team(h2);

    timer.start();
    boolean result12 = Team.validPlacementExists(t1, t2);
    boolean result21 = Team.validPlacementExists(t2, t1);
    timer.stop();

    if (result12 != expected12 || result21 != expected21) {
      throw new TestFailureException("");
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}

class Team {
  private static class Player implements Comparable<Player> {
    public Integer height;

    public Player(Integer h) {
      height = h;
    }

    @Override
    public int compareTo(Player that) {
      return Integer.compare(height, that.height);
    }
  }

  public Team(List<Integer> height) {
    players = height.stream().map(h -> new Player(h)).collect(Collectors.toList());
  }

  // Checks if A can be placed in front of B.
  public static boolean validPlacementExists(Team A, Team B) {
    // Implement this placeholder.
    return true;
  }

  private List<Player> players;
}
