// @library
package epi.test_framework;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;

public class TestConfig {
  public String testDataDir;
  public String testDataFile;
  public boolean runAllTests;
  public boolean verbose;
  public TriBool ttyMode;
  public TriBool colorMode;
  public long timeoutSeconds;

  public TestConfig(String testDataFile, long timeoutSeconds) {
    this.testDataFile = testDataFile;
    this.runAllTests = false;
    this.verbose = true;
    this.ttyMode = TriBool.INDETERMINATE;
    this.colorMode = TriBool.INDETERMINATE;
    this.timeoutSeconds = timeoutSeconds;
  }

  private static String getParam(String[] commandlineArgs, int i,
                                 String argName) {
    if (i >= commandlineArgs.length) {
      throw new RuntimeException("CL: Missing parameter for " + argName);
    }
    return commandlineArgs[i];
  }

  private static void printUsageAndExit() {
    String usageString =
        "usage: <program name> [-h] [--test-data-dir [TEST_DATA_DIR]]\n"
        + "                      [--run-all-tests] [--no-verbose]\n"
        +
        "                      [--force-tty] [--no-tty] [--force-color] [--no-color]\n"
        + "\n"
        + "optional arguments:\n"
        + "  -h, --help            show this help message and exit\n"
        + "  --test-data-dir [TEST_DATA_DIR]\n"
        + "                        path to test_data directory\n"
        +
        "  --run-all-tests       continue execution even if one or several tests failed\n"
        +
        "  --no-verbose          suppress failure description on test failure\n"
        +
        "  --force-tty           enable tty features (like printing output on the same\n"
        +
        "                        line) even in case stdout is not a tty device\n"
        + "  --no-tty              never use tty features\n"
        +
        "  --force-color         enable colored output even in case stdout is not a tty\n"
        + "                        device\n"
        + "  --no-color            never use colored output\n";
    System.out.print(usageString);
    System.exit(0);
  }

  public static TestConfig fromCommandLine(String testDataFile,
                                           long timeoutSeconds,
                                           String[] commandlineArgs) {
    TestConfig config = new TestConfig(testDataFile, timeoutSeconds);

    for (int i = 0; i < commandlineArgs.length; i++) {
      switch (commandlineArgs[i]) {
        case "--test-data-dir":
          config.testDataDir =
              getParam(commandlineArgs, ++i, "--test-data-dir");
          break;
        case "--run-all-tests":
          config.runAllTests = true;
          break;
        case "--no-verbose":
          config.verbose = false;
          break;
        case "--force-tty":
          config.ttyMode = TriBool.TRUE;
          break;
        case "--no-tty":
          config.ttyMode = TriBool.FALSE;
          break;
        case "--force-color":
          config.colorMode = TriBool.TRUE;
          break;
        case "--no-color":
          config.colorMode = TriBool.FALSE;
          break;
        case "--help":
        case "-h":
          printUsageAndExit();
          break;
        default:
          throw new RuntimeException("CL: Unrecognized argument: " +
                                     commandlineArgs[i]);
      }
    }

    if (config.testDataDir != null && !config.testDataDir.isEmpty()) {
      if (!Files.isDirectory(Paths.get(config.testDataDir))) {
        throw new RuntimeException(String.format(
            "CL: --test_data_dir argument (%s) is not a directory",
            config.testDataDir));
      }
    } else {
      config.testDataDir = TestUtils.getDefaultTestDataDirPath();
    }

    return config;
  }
}
