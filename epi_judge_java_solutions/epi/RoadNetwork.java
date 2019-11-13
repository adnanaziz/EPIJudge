package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RoadNetwork {
  @EpiUserType(ctorParams = {int.class, int.class, int.class})

  public static class HighwaySection {
    public int x, y, distance;

    public HighwaySection(int x, int y, int distance) {
      this.x = x;
      this.y = y;
      this.distance = distance;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      HighwaySection that = (HighwaySection)o;
      return x == that.x && y == that.y && distance == that.distance;
    }

    @Override
    public String toString() {
      return "[" + x + ", " + y + ", " + distance + "]";
    }
  }

  @EpiTest(testDataFile = "road_network.tsv")

  public static HighwaySection
  findBestProposals(List<HighwaySection> H, List<HighwaySection> P, int n) {

    // graph stores the shortest path distances between all pairs of vertices.
    List<List<Integer>> graph = new ArrayList<>(n);
    for (int i = 0; i < n; ++i) {
      graph.add(new ArrayList<>(Collections.nCopies(n, Integer.MAX_VALUE)));
    }
    for (int i = 0; i < n; ++i) {
      graph.get(i).set(i, 0);
    }
    // Builds an undirected graph graph based on existing highway sections H.
    for (HighwaySection h : H) {
      graph.get(h.x).set(h.y, h.distance);
      graph.get(h.y).set(h.x, h.distance);
    }

    // Performs Floyd Warshall to build the shortest path between vertices.
    floydWarshall(graph);

    // Examines each proposal for shorter distance for all pairs.
    int bestDistanceSaving = Integer.MIN_VALUE;
    HighwaySection bestProposal = new HighwaySection(-1, -1, 0); // Default.
    for (HighwaySection p : P) {
      int proposalSaving = 0;
      for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
          int saving =
              graph.get(a).get(b) -
              Math.min(
                  graph.get(a).get(p.x) + p.distance + graph.get(p.y).get(b),
                  graph.get(a).get(p.y) + p.distance + graph.get(p.x).get(b));
          proposalSaving += Math.max(saving, 0);
        }
      }
      if (proposalSaving > bestDistanceSaving) {
        bestDistanceSaving = proposalSaving;
        bestProposal = p;
      }
    }
    return bestProposal;
  }

  private static void floydWarshall(List<List<Integer>> graph) {
    for (int k = 0; k < graph.size(); ++k) {
      for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
          if (graph.get(i).get(k) != Integer.MAX_VALUE &&
              graph.get(k).get(j) != Integer.MAX_VALUE &&
              graph.get(i).get(j) > graph.get(i).get(k) + graph.get(k).get(j)) {
            graph.get(i).set(j, graph.get(i).get(k) + graph.get(k).get(j));
          }
        }
      }
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RoadNetwork.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
