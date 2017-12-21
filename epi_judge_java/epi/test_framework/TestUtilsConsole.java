// @library
package epi.test_framework;

import java.util.List;

public class TestUtilsConsole {
  public static String escapeNewline(String s) {
    return s.replace("\n", "\\n").replace("\r", "\\r");
  }

  public static void returnCaretIfTtyOutput() {
    if (TestResult.useTtyOutput()) {
      System.out.print('\r');
    } else {
      System.out.print('\n');
    }
  }

  public static void printTestResult(TestResult test_result, int testNr,
                                     int totalTests, String diagnostic,
                                     TestTimer timer) {
    returnCaretIfTtyOutput();

    String totalTestsStr = String.valueOf(totalTests);
    System.out.printf(
        "Test %s (%" + String.valueOf(totalTestsStr.length()) + "d/%s)",
        test_result.toString(), testNr, totalTestsStr);

    if (timer.hasValidResult()) {
      System.out.printf(" [%s]",
                        timer.durationToString(timer.getMicroseconds()));
    }

    if (test_result != TestResult.PASSED) {
      System.out.println(" " + diagnostic);
    }
  }

  public static void printFailedTest(List<String> arguments,
                                     TestOutput testOutput,
                                     String testExplanation) {
    for (int i = 0; i < arguments.size(); i++) {
      System.out.printf("\tArg %d: %s\n", i + 1,
                        escapeNewline(arguments.get(i)));
    }

    if (testOutput == null) {
      return;
    }

    if (testOutput.expected != TestOutput.EMPTY_OBJECT) {
      System.out.printf("\tExpected: %s\n",
                        escapeNewline(String.valueOf(testOutput.expected)));
    }
    if (testOutput.result != TestOutput.EMPTY_OBJECT) {
      System.out.printf("\tResult:   %s\n",
                        escapeNewline(String.valueOf(testOutput.result)));
    }
    if (!testExplanation.equals("TODO") && !testExplanation.equals("")) {
      System.out.printf("\tExplanation: %s\n", testExplanation);
    }
  }
}
