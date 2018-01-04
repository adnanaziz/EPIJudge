package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.EpiTestExpectedType;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class RemoveDuplicates {
  @EpiUserType(ctorParams = {String.class, String.class})
  //@include
  public static class Name implements Comparable<Name> {
    String firstName;
    String lastName;

    public Name(String first, String last) {
      firstName = first;
      lastName = last;
    }

    @Override
    public boolean equals(Object obj) {
      if (obj == null || !(obj instanceof Name)) {
        return false;
      }
      if (this == obj) {
        return true;
      }
      Name name = (Name)obj;
      return firstName.equals(name.firstName) && lastName.equals(name.lastName);
    }

    @Override
    public String toString() {
      return firstName;
    }

    @Override
    public int compareTo(Name name) {
      int cmpFirst = firstName.compareTo(name.firstName);
      if (cmpFirst != 0) {
        return cmpFirst;
      }
      return lastName.compareTo(name.lastName);
    }
  }

  public static void eliminateDuplicate(List<Name> A) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "remove_duplicates.tsv")
  public static List<Name> eliminateDuplicateWrapper(List<Name> data) {
    eliminateDuplicate(data);
    return data;
  }

  @EpiTestComparator
  public static BiPredicate<List<String>, List<Name>> comp =
      (expected, result) -> {
    if (result == null) {
      return false;
    }
    Collections.sort(expected);
    Collections.sort(result);
    if (expected.size() != result.size()) {
      return false;
    }
    for (int i = 0; i < result.size(); i++) {
      if (!expected.get(i).equals(result.get(i).firstName)) {
        return false;
      }
    }
    return true;
  };

  @EpiTestExpectedType
  public static List<Class<?>> expectedType =
      Arrays.asList(List.class, String.class);

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
