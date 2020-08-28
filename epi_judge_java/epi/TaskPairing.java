package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;
import epi.test_framework.EpiTestComparator;

import java.util.List;
import java.util.Comparator;

public class TaskPairing {
  @EpiUserType(ctorParams = {Integer.class, Integer.class})

  public static class PairedTasks {
    public Integer task1;
    public Integer task2;

    public PairedTasks(Integer task1, Integer task2) {
      this.task1 = task1;
      this.task2 = task2;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      PairedTasks that = (PairedTasks)o;

      return task1.equals(that.task1) && task2.equals(that.task2) ||
        task1.equals(that.task2) && task2.equals(that.task1);
    }

    @Override
    public String toString() {
      return "[" + task1 + ", " + task2 + "]";
    }
  }

  private static class PairedTasksComparator implements Comparator<PairedTasks> {
    @Override
    public int compare(PairedTasks p1, PairedTasks p2) {
      if (p1 == null) {
        return p2 == null ? 0 : -1;
      }

      if (p1.equals(p2)) {
        return 0;
      }

      Integer minP1 = Math.min(p1.task1, p1.task2);
      Integer minP2 = Math.min(p2.task1, p2.task2);
      int minCompare = minP1.compareTo(minP2);

      if (minCompare != 0) {
        return minCompare;
      } else {
        Integer maxP1 = Math.max(p1.task1, p1.task2);
        Integer maxP2 = Math.max(p2.task1, p2.task2);
        return maxP1.compareTo(maxP2);
      }
    }
  }

  @EpiTest(testDataFile = "task_pairing.tsv")

  public static List<PairedTasks>
  optimumTaskAssignment(List<Integer> taskDurations) {
    // TODO - you fill in here.
    return null;
  }

  @EpiTestComparator
  public static boolean comp(List<PairedTasks> expected, List<PairedTasks> result) {
    if (result == null) {
      return false;
    }
    result.sort(new PairedTasksComparator());
    expected.sort(new PairedTasksComparator());
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TaskPairing.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
