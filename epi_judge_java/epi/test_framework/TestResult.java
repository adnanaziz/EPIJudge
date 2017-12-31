// @library
package epi.test_framework;

public enum TestResult {
  FAILED,
  PASSED,
  TIMEOUT,
  UNKNOWN_EXCEPTION,
  STACK_OVERFLOW;

  private static String FG_RED = "\033[31m";
  private static String FG_GREEN = "\033[32m";
  private static String FG_BLUE = "\033[34m";
  private static String FG_DEFAULT = "\033[39m";

  private static Boolean isWindows = null;

  public static boolean useTtyOutput() {
    // System.console() result is cached by Java
    return System.console() != null;
  }

  public static boolean platformSupportsColor() {
    if (isWindows == null) {
      isWindows = System.getProperty("os.name").startsWith("Windows");
    }
    return !isWindows;  // Windows doesn't support coloring through escape codes
  }

  private static String colored(String text, String Color) {
    if (useTtyOutput() && platformSupportsColor()) {
      return Color + text + FG_DEFAULT;
    } else {
      return text;
    }
  }

  @Override
  public String toString() {
    switch (this) {
      case PASSED:
        return colored("PASSED", FG_GREEN);
      case FAILED:
        return colored("FAILED", FG_RED);
      case TIMEOUT:
        return colored("TIMEOUT", FG_BLUE);
      case UNKNOWN_EXCEPTION:
        return colored("UNHANDLED EXCEPTION", FG_RED);
      case STACK_OVERFLOW:
        return colored("STACK OVERFLOW", FG_RED);
      default:
        throw new RuntimeException("Unknown TestResult");
    }
  }
}
