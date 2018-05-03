
package epi.test_framework;

import java.nio.file.Files;
import java.nio.file.Paths;

public class TestConfig {
  public String testDataDir;
  public String testFile;
  public String testDataFile;
  public boolean verbose;
  public boolean analyzeComplexity;
  public TriBool ttyMode;
  public TriBool colorMode;
  public boolean updateJs;
  public long timeoutSeconds;
  public int numFailedTestsBeforeStop;

  public TestConfig(String testFile, String testDataFile, long timeoutSeconds,
                    int numFailedTestsBeforeStop) {
    this.testFile = testFile;
    this.testDataFile = testDataFile;
    this.verbose = true;
    this.analyzeComplexity = false;
    this.ttyMode = TriBool.INDETERMINATE;
    this.colorMode = TriBool.INDETERMINATE;
    this.updateJs = false;
    this.timeoutSeconds = timeoutSeconds;
    this.numFailedTestsBeforeStop = numFailedTestsBeforeStop;
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
        "usage: <program name> [-h] [--test-data-dir [TEST_DATA_DIR]] [--no-verbose]\n"
        +
        "                    [--force-tty] [--no-tty] [--force-color] [--no-color]\n"
        + "\n"
        + "optional arguments:\n"
        +
        "  -h, --help                         show this help message and exit\n"
        + "  --test-data-dir [TEST_DATA_DIR]    path to test_data directory\n"
        +
        "  --no-verbose                       suppress failure description on test failure\n"
        +
        "  --force-tty                        enable tty features (like printing output on the same line) even in case stdout is not a tty device\n"
        + "  --no-tty                           never use tty features\n"
        +
        "  --force-color                      enable colored output even in case stdout is not a tty device\n"
        + "  --no-color                         never use colored output\n"
        + "  --no-update-js                     no update problem_mapping.js\n";
    System.out.print(usageString);
    System.exit(0);
  }

  public static TestConfig fromCommandLine(String testFile, String testDataFile,
                                           long timeoutSeconds,
                                           int numFailedTestsBeforeStop,
                                           String[] commandlineArgs) {
    // Set numFailedTestsBeforeStop to 0, means users want to run as many as
    // tests in one run.
    if (numFailedTestsBeforeStop == 0) {
      numFailedTestsBeforeStop = Integer.MAX_VALUE;
    }

    TestConfig config = new TestConfig(testFile, testDataFile, timeoutSeconds,
                                       numFailedTestsBeforeStop);

    for (int i = 0; i < commandlineArgs.length; i++) {
      switch (commandlineArgs[i]) {
        case "--test-data-dir":
          config.testDataDir =
              getParam(commandlineArgs, ++i, "--test-data-dir");
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
        case "--no-update-js":
          config.updateJs = false;
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
