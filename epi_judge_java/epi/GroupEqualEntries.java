package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class GroupEqualEntries {
  @EpiUserType(ctorParams = {Integer.class, String.class})

  public static class Person {
    public Integer age;
    public String name;

    public Person(Integer k, String n) {
      age = k;
      name = n;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o)
        return true;
      if (o == null || getClass() != o.getClass())
        return false;

      Person person = (Person)o;

      if (!age.equals(person.age))
        return false;
      return name.equals(person.name);
    }

    @Override
    public int hashCode() {
      int result = age.hashCode();
      result = 31 * result + name.hashCode();
      return result;
    }
  }

  public static void groupByAge(List<Person> people) {
    // Implement this placeholder.
    return;
  }

  private static Map<Person, Integer> buildMultiset(List<Person> people) {
    Map<Person, Integer> m = new HashMap<>();
    for (Person p : people) {
      m.put(p, m.getOrDefault(p, 0) + 1);
    }
    return m;
  }

  @EpiTest(testfile = "group_equal_entries.tsv")
  public static void groupByAgeWrapper(TestTimer timer, List<Person> people)
      throws TestFailureException {
    if (people.isEmpty()) {
      return;
    }
    Map<Person, Integer> values = buildMultiset(people);

    timer.start();
    groupByAge(people);
    timer.stop();

    Map<Person, Integer> newValues = buildMultiset(people);
    if (!values.equals(newValues)) {
      throw new TestFailureException("Entry set changed");
    }
    int lastAge = people.get(0).age;
    Set<Integer> ages = new HashSet<>();

    for (Person p : people) {
      if (ages.contains(p.age)) {
        throw new TestFailureException("Entries are not grouped by age");
      }
      if (p.age != lastAge) {
        ages.add(lastAge);
        lastAge = p.age;
      }
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
