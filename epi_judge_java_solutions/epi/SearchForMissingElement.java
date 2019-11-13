package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.List;

public class SearchForMissingElement {
  @EpiUserType(ctorParams = {Integer.class, Integer.class})

  public static class DuplicateAndMissing {
    public Integer duplicate;
    public Integer missing;

    public DuplicateAndMissing(Integer duplicate, Integer missing) {
      this.duplicate = duplicate;
      this.missing = missing;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      DuplicateAndMissing that = (DuplicateAndMissing)o;

      if (!duplicate.equals(that.duplicate)) {
        return false;
      }
      return missing.equals(that.missing);
    }

    @Override
    public int hashCode() {
      int result = duplicate.hashCode();
      result = 31 * result + missing.hashCode();
      return result;
    }

    @Override
    public String toString() {
      return "duplicate: " + duplicate + ", missing: " + missing;
    }
  }

  @EpiTest(testDataFile = "find_missing_and_duplicate.tsv")

  public static DuplicateAndMissing findDuplicateMissing(List<Integer> A) {

    // Compute the XOR of all numbers from 0 to |A| - 1 and all entries in A.
    int missXorDup = 0;
    for (int i = 0; i < A.size(); ++i) {
      missXorDup ^= i ^ A.get(i);
    }

    // We need to find a bit that's set to 1 in missXorDup. Such a bit
    // must exist if there is a single missing number and a single duplicated
    // number in A.
    //
    // The bit-fiddling assignment below sets all of bits in differBit to 0
    // except for the least significant bit in missXorDup that's 1.
    int differBit = missXorDup & (~(missXorDup - 1));
    int missOrDup = 0;
    for (int i = 0; i < A.size(); ++i) {
      // Focus on entries and numbers in which the differBit-th bit is 1.
      if ((i & differBit) != 0) {
        missOrDup ^= i;
      }
      if ((A.get(i) & differBit) != 0) {
        missOrDup ^= A.get(i);
      }
    }

    // missOrDup is either the missing value or the duplicated entry. If
    // missOrDup is in A, missOrDup is the duplicate; otherwise, missOrDup is
    // the missing value.
    return A.contains(missOrDup)
        ? new DuplicateAndMissing(missOrDup, missOrDup ^ missXorDup)
        : new DuplicateAndMissing(missOrDup ^ missXorDup, missOrDup);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SearchForMissingElement.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
