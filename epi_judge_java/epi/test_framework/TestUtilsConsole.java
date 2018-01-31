// @library
package epi.test_framework;

import java.util.List;

public class TestUtilsConsole {
  public static String escapeNewline(String s) {
    return s.replace("\n", "\\n").replace("\r", "\\r");
  }

  public static void returnCaretIfTtyOutput() {
    if (Platform.useTtyOutput()) {
      System.out.print('\r');
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
    returnCaretIfTtyOutput();

    String totalTestsStr = String.valueOf(totalTests);
    System.out.print("Test ");
    printTestResult(testResult);
    System.out.printf(" (%" + String.valueOf(totalTestsStr.length()) + "d/%s)",
                      testNr, totalTestsStr);

    if (timer.hasValidResult()) {
      System.out.printf(" [%s]",
                        TestTimer.durationToString(timer.getMicroseconds()));
    }

    if (testResult != TestResult.PASSED) {
      System.out.println(" " + diagnostic);
    }
  }

  private static String genSpaces(int count) {
    return new String(new char[count]).replace('\0', ' ');
  }

  public static void printFailedTest(List<String> paramNames,
                                     List<String> arguments,
                                     TestOutput testOutput,
                                     String testExplanation) {
    String expectedStr = "expected";
    String resultStr = "result";
    String explanationStr = "explanation";

    boolean hasExpected =
        testOutput != null && testOutput.expected != TestOutput.EMPTY_OBJECT;
    boolean hasResult =
        testOutput != null && testOutput.result != TestOutput.EMPTY_OBJECT;
    boolean hasExplanation =
        !testExplanation.equals("TODO") && !testExplanation.equals("");

    int maxColSize = hasExplanation
                         ? explanationStr.length()
                         : hasExpected ? expectedStr.length()
                                       : hasResult ? resultStr.length() : 0;

    for (String param : paramNames) {
      if (param.length() > maxColSize) maxColSize = param.length();
    }

    for (int i = 0; i < arguments.size(); i++) {
      System.out.printf("\t%s: %s%s\n", paramNames.get(i),
                        genSpaces(maxColSize - paramNames.get(i).length()),
                        escapeNewline(arguments.get(i)));
    }

    if (hasExpected) {
      System.out.printf("\t%s: %s%s\n", expectedStr,
                        genSpaces(maxColSize - expectedStr.length()),
                        escapeNewline(String.valueOf(testOutput.expected)));
    }
    if (hasResult) {
      System.out.printf("\t%s: %s%s\n", resultStr,
                        genSpaces(maxColSize - resultStr.length()),
                        escapeNewline(String.valueOf(testOutput.result)));
    }
    if (hasExplanation) {
      System.out.printf("\t%s: %s%s\n", explanationStr,
                        genSpaces(maxColSize - explanationStr.length()),
                        testExplanation);
    }
  }
}
