package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.EpiTestComparator;

import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class ValidIpAddresses {
  @EpiTest(testfile = "valid_ip_addresses.tsv")

  public static List<String> getValidIpAddress(String s) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
  @SuppressWarnings("unchecked")
  public static BiPredicate<Object, Object> comp = (Object expected, Object result) -> {
    List<String> a = (List<String>) expected;
    List<String> b = (List<String>) result;
    Collections.sort(a);
    Collections.sort(b);
    return a.equals(b);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
