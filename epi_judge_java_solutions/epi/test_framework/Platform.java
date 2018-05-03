
package epi.test_framework;

public class Platform {
  private static Boolean isWindows;
  private static Boolean is64Bit;
  private static TriBool dllLoaded = TriBool.INDETERMINATE;
  private static boolean enableTtyOutput = false;
  private static boolean enableColorOutput = false;

  public static void stdOutClearLine() { System.out.print("\r"); }

  public static void setOutputOpts(TriBool ttyMode, TriBool colorMode) {
    enableTtyOutput = ttyMode.getOrDefault(System.console() != null);
    enableColorOutput = colorMode.getOrDefault(enableTtyOutput);
    initColorOutput();
  }

  public static boolean useTtyOutput() { return enableTtyOutput; }

  public static boolean useColorOutput() { return enableColorOutput; }

  public static boolean runningOnWin() {
    if (isWindows == null) {
      isWindows = System.getProperty("os.name").startsWith("Windows");
    }
    return isWindows;
  }

  public static boolean runningOn64BitVM() {
    if (is64Bit == null) {
      String bits = System.getProperty("sun.arch.data.model", "?");
      switch (bits) {
      case "64":
        is64Bit = true;
        break;
      case "?":
        is64Bit =
            System.getProperty("java.vm.name").toLowerCase().contains("64");
        break;
      default:
        is64Bit = false;
        break;
      }
    }
    return is64Bit;
  }

  private static void initColorOutput() {
    if (runningOnWin() && useColorOutput() &&
        dllLoaded == TriBool.INDETERMINATE) {
      String dllName =
          runningOn64BitVM() ? "console_color_64" : "console_color_32";

      try {
        System.loadLibrary(dllName);
        dllLoaded = TriBool.TRUE;
      } catch (UnsatisfiedLinkError ex) {
        dllLoaded = TriBool.FALSE;
        System.out.printf(
            "Warning: %s.dll was not found. Colored output is disabled.\n"
                +
                "In order to enable it, pass -Djava.library.path=<path to EPIJudge>/epi_judge_java/epi/test_framework option to java.\n",
            dllName);
      }
    }
  }

  public static int winSetConsoleTextAttribute(int attr) {
    if (dllLoaded == TriBool.TRUE) {
      return winSetConsoleTextAttributeImpl(attr);
    }
    return 0;
  }

  /**
   * Interface to the native wrapper of WinAPI.
   * Set CONSOLE_SCREEN_BUFFER_INFO.wAttributes to attr for the stdout handle.
   * @param attr - new value for wAttributes
   * @return previous value of wAttributes
   */
  private static native int winSetConsoleTextAttributeImpl(int attr);
}
