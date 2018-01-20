// @library
package epi.test_framework;

public class Platform {
  private static Boolean isWindows;
  private static Boolean is64Bit;
  private static boolean dllLoaded = false;

  public static boolean enableColorOutput = true;

  static {
    if (runningOnWin() && useColorOutput()) {
      String dllName =
          runningOn64BitVM() ? "console_color_64" : "console_color_32";

      try {
        System.loadLibrary(dllName);
        dllLoaded = true;
      } catch (UnsatisfiedLinkError ex) {
        System.out.printf(
            "Warning: %s.dll was not found. Colored output is disabled.\nIn order to enable it, pass -Djava.library.path=<path to EPIJudge>/epi_judge_java/epi/test_framework option to java.\n",
            dllName);
      }
    }
  }

  public static boolean runningOnWin() {
    if (isWindows == null) {
      isWindows = System.getProperty("os.name").startsWith("Windows");
    }
    return isWindows;
  }

  public static boolean runningOn64BitVM() {
    if (is64Bit == null) {
      String bits = System.getProperty("sun.arch.data.model", "?");
      if (bits.equals("64")) {
        is64Bit = true;
      } else if (bits.equals("?")) {
        is64Bit =
            System.getProperty("java.vm.name").toLowerCase().indexOf("64") >= 0;
      } else {
        is64Bit = false;
      }
    }
    return is64Bit;
  }

  public static boolean useTtyOutput() {
    // System.console() result is cached by Java
    return System.console() != null;
  }

  public static boolean useColorOutput() {
    return useTtyOutput() && enableColorOutput;
  }

  public static int winSetConsoleTextAttribute(int attr) {
    if (dllLoaded) {
      return winSetConsoleTextAttributeImpl(attr);
    }
    return 0;
  }

  private static native int winSetConsoleTextAttributeImpl(int attr);
}
