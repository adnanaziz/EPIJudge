package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;

public class IsStringInMatrix {

  private static class Attempt {
    public Integer x;
    public Integer y;
    public Integer offset;

    public Attempt(Integer x, Integer y, Integer offset) {
      this.x = x;
      this.y = y;
      this.offset = offset;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      Attempt cacheEntry = (Attempt)o;

      if (x != null ? !x.equals(cacheEntry.x) : cacheEntry.x != null) {
        return false;
      }
      if (y != null ? !y.equals(cacheEntry.y) : cacheEntry.y != null) {
        return false;
      }
      if (offset != null ? !offset.equals(cacheEntry.offset)
                         : cacheEntry.offset != null) {
        return false;
      }

      return true;
    }

    @Override
    public int hashCode() {
      return Objects.hash(x, y, offset);
    }
  }

  @EpiTest(testDataFile = "is_string_in_matrix.tsv")
  public static boolean isPatternContainedInGrid(List<List<Integer>> grid,
                                                 List<Integer> pattern) {

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid.get(i).size(); ++j) {
        if (isPatternSuffixContainedStartingAtXY(
                grid, i, j, pattern, /*offset=*/0, new HashSet<>())) {
          return true;
        }
      }
    }
    return false;
  }

  // Each entry in previousAttempts is a point in the grid and suffix of pattern
  // (identified by its offset). Presence in previousAttempts indicates the
  // suffix is not contained in the grid starting from that point.
  private static boolean
  isPatternSuffixContainedStartingAtXY(List<List<Integer>> grid, int x, int y,
                                       List<Integer> pattern, int offset,
                                       Set<Attempt> previousAttempts) {
    if (pattern.size() == offset) {
      // Nothing left to complete.
      return true;
    }
    // Early return if (x, y) lies outside the grid or the character does not
    // match or we have already tried this combination.
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid.get(x).size() ||
        previousAttempts.contains(new Attempt(x, y, offset)) ||
        !grid.get(x).get(y).equals(pattern.get(offset))) {
      return false;
    }

    for (List<Integer> nextXY : List.of(List.of(x - 1, y), List.of(x + 1, y),
                                        List.of(x, y - 1), List.of(x, y + 1))) {
      if (isPatternSuffixContainedStartingAtXY(grid, nextXY.get(0),
                                               nextXY.get(1), pattern,
                                               offset + 1, previousAttempts)) {
        return true;
      }
    }
    previousAttempts.add(new Attempt(x, y, offset));
    return false;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IsStringInMatrix.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
