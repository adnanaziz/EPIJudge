
package epi.test_framework;

public class ConsoleColor {
  public enum Color { FG_RED, FG_GREEN, FG_BLUE, FG_YELLOW, FG_DEFAULT }

  private static int getColorCodeWin(Color color) {
    switch (color) {
    case FG_RED:
      return 4 | 8;
    case FG_GREEN:
      return 2 | 8;
    case FG_BLUE:
      return 1 | 8;
    case FG_YELLOW:
      return 6 | 8;
    case FG_DEFAULT:
    default:
      return 7;
    }
  }

  private static String getColorCodeUnix(Color color) {
    switch (color) {
    case FG_RED:
      return "\033[31m";
    case FG_GREEN:
      return "\033[32m";
    case FG_BLUE:
      return "\033[34m";
    case FG_YELLOW:
      return "\033[33m";
    case FG_DEFAULT:
    default:
      return "\033[39m";
    }
  }

  public static void printStdOutColored(Color color, Object value) {
    if (!Platform.useColorOutput()) {
      System.out.print(value);
      return;
    }

    if (Platform.runningOnWin()) {
      System.out.flush();
      int oldTextAttr =
          Platform.winSetConsoleTextAttribute(getColorCodeWin(color));

      System.out.print(value);

      System.out.flush();
      Platform.winSetConsoleTextAttribute(oldTextAttr);
    } else {
      System.out.printf("%s%s%s", getColorCodeUnix(color),
                        String.valueOf(value),
                        getColorCodeUnix(Color.FG_DEFAULT));
    }
  }
}
