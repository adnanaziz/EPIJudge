package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class ReplaceAndRemove {
  public static int replaceAndRemove(int size, char[] s) {
    // Implement this placeholder.
    return 0;
  }

  @EpiTest(testfile = "replace_and_remove.tsv")
  public static List<String> replaceAndRemoveWrapper(
      TestTimer timer, Integer size, List<String> inputS) {
    char[] s = new char[inputS.size()];
    for (int i = 0; i < size; ++i) {
      if (!inputS.get(i).isEmpty()) {
        s[i] = inputS.get(i).charAt(0);
      }
    }
    timer.start();
    Integer resSize = replaceAndRemove(size, s);
    timer.stop();

    List<String> result = new ArrayList<>();
    for (int i = 0; i < resSize; ++i) {
      result.add(Character.toString(s[i]));
    }
    return result;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
