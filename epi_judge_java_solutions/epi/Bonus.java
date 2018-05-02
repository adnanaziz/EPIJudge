package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Bonus {

  private static class EmployeeData {
    public Integer productivity;
    public Integer index;

    public EmployeeData(Integer productivity, Integer index) {
      this.productivity = productivity;
      this.index = index;
    }
  }

  private static final int DEFAULT_INITIAL_CAPACITY = 16;

  @EpiTest(testDataFile = "bonus.tsv")

  public static Integer calculateBonus(List<Integer> productivity) {

    PriorityQueue<EmployeeData> minHeap = new PriorityQueue<>(
        DEFAULT_INITIAL_CAPACITY,
        (o1, o2) -> Integer.compare(o1.productivity, o2.productivity));
    for (int i = 0; i < productivity.size(); ++i) {
      minHeap.add(new EmployeeData(productivity.get(i), i));
    }

    // Initially assigns one ticket to everyone.
    List<Integer> tickets =
        new ArrayList<>(Collections.nCopies(productivity.size(), 1));
    // Fills tickets from lowest rating to highest rating.
    while (!minHeap.isEmpty()) {
      EmployeeData p = minHeap.peek();
      int nextDev = minHeap.peek().index;
      // Handles the left neighbor.
      if (nextDev > 0 &&
          productivity.get(nextDev) > productivity.get(nextDev - 1)) {
        tickets.set(nextDev, tickets.get(nextDev - 1) + 1);
      }
      // Handles the right neighbor.
      if (nextDev + 1 < tickets.size() &&
          productivity.get(nextDev) > productivity.get(nextDev + 1)) {
        tickets.set(nextDev, Math.max(tickets.get(nextDev),
                                      tickets.get(nextDev + 1) + 1));
      }
      minHeap.remove(p);
    }
    return tickets.stream().mapToInt(Integer::intValue).sum();
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Bonus.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
