
package epi.test_framework;

import java.util.List;

public class TestUtilsConsole {
  private static boolean caretAtLineStart = true;

  public static String escapeNewline(String s) {
    return s.replace("\n", "\\n").replace("\r", "\\r");
  }

  public static void clearLineIfTty() {
    if (Platform.useTtyOutput()) {
      Platform.stdOutClearLine();
    } else {
      System.out.print('\n');
    }
  }

  public static void printTestResult(TestResult testResult) {
    switch (testResult) {
    case PASSED:
      ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_GREEN, "PASSED");
      break;
    case FAILED:
      ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_RED, "FAILED");
      break;
    case TIMEOUT:
      ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_BLUE, "TIMEOUT");
      break;
    case UNKNOWN_EXCEPTION:
      ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_RED,
                                      "UNHANDLED EXCEPTION");
      break;
    case STACK_OVERFLOW:
      ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_RED,
                                      "STACK OVERFLOW");
      break;
    default:
      throw new RuntimeException("Unknown TestResult");
    }
  }

  public static void printTestInfo(TestResult testResult, int testNr,
                                   int totalTests, String diagnostic,
                                   TestTimer timer) {
    if (!caretAtLineStart) {
      clearLineIfTty();
    }

    String totalTestsStr = String.valueOf(totalTests);
    System.out.print("Test ");
    printTestResult(testResult);
    System.out.printf(" (%" + String.valueOf(totalTestsStr.length()) + "d/%s)",
                      testNr, totalTestsStr);

    if (timer != null) {
      System.out.printf(" [%s]",
                        TestTimer.durationToString(timer.getMicroseconds()));
    }
    caretAtLineStart = false;

    if (testResult != TestResult.PASSED) {
      System.out.println(" " + diagnostic);
      caretAtLineStart = true;
    }
  }

  private static String genSpaces(int count) {
    return new String(new char[count]).replace('\0', ' ');
  }

  public static void printFailedTest(List<String> paramNames,
                                     List<String> arguments,
                                     TestFailure testFailure) {
    int maxColSize = testFailure.getMaxPropertyNameLength();

    for (String param : paramNames) {
      if (param.length() > maxColSize) {
        maxColSize = param.length();
      }
    }

    ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_YELLOW,
                                    "Arguments\n");

    for (int i = 0; i < arguments.size(); i++) {
      System.out.print("\t");
      ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_YELLOW,
                                      paramNames.get(i));
      System.out.printf(": %s%s\n",
                        genSpaces(maxColSize - paramNames.get(i).length()),
                        escapeNewline(arguments.get(i)));
    }

    List<TestFailure.Property> properties = testFailure.getProperties();
    if (!properties.isEmpty()) {
      ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_YELLOW,
                                      "\nFailure info\n");
      for (TestFailure.Property prop : properties) {
        System.out.print("\t");
        ConsoleColor.printStdOutColored(ConsoleColor.Color.FG_YELLOW,
                                        prop.name());
        System.out.printf(": %s%s\n",
                          genSpaces(maxColSize - prop.name().length()),
                          escapeNewline(String.valueOf(prop.value())));
      }
    }
  }

  public static void showComplexityNotification() {
    if (Platform.useTtyOutput()) {
      System.out.print("Time complexity:\r");
    }
  }

  public static void printPostRunStats(int testsPassed, int totalTests,
                                       String complexity,
                                       List<Long> durations) {
    if (!durations.isEmpty()) {
      if (!complexity.isEmpty()) {
        System.out.printf("Time complexity: %s\n", complexity);
      }

      long[] avgMedian = TestTimer.avgAndMedianFromDuration(durations);
      System.out.printf("Average running time: %s\nMedian running time:  %s\n",
                        TestTimer.durationToString(avgMedian[0]),
                        TestTimer.durationToString(avgMedian[1]));
    }

    if (testsPassed < totalTests) {
      System.out.printf("*** You've passed %d/%d tests. ***\n", testsPassed,
                        totalTests);
    } else {
      System.out.println("*** You've passed ALL tests. Congratulations! ***");
    }
  }
}
