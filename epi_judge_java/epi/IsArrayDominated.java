package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.List;
import java.util.stream.Collectors;

public class IsArrayDominated {
  @EpiTest(testfile = "is_array_dominated.tsv")
  public static void
  validPlacementExistsWrapper(TestTimer timer, List<Integer> team0,
                              List<Integer> team1, boolean expected01,
                              boolean expected10) throws TestFailureException {
    Team t0 = new Team(team0);
    Team t1 = new Team(team1);

    timer.start();
    if (Team.validPlacementExists(t0, t1) != expected01 ||
        Team.validPlacementExists(t1, t0) != expected10) {
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

    public Player(Integer h) { height = h; }

    @Override
    public int compareTo(Player that) {
      return Integer.compare(height, that.height);
    }
  }

  public Team(List<Integer> height) {
    players =
        height.stream().map(h -> new Player(h)).collect(Collectors.toList());
  }

  // Checks if team0 can be placed in front of team1.
  public static boolean validPlacementExists(Team team0, Team team1) {
    // Implement this placeholder.
    return true;
  }

  private List<Player> players;
}
