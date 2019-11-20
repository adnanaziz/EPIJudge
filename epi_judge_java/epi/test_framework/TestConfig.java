
package epi.test_framework;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.function.BiFunction;
import java.util.function.Function;

/**
 * This class contains parameters that control test execution
 */
public class TestConfig {
  /**
   * Path to directory with .tsv files
   */
  public String testDataDir;
  /**
   * Program source filename
   */
  public String testFile;
  /**
   * Name of corresponding .tsv file
   */
  public String testDataFile;
  /**
   * If TRUE, enable advanced output (mainly usage of \r)
   * If INDETERMINATE, try to autodetect if output is console
   */
  public TriBool ttyMode;
  /**
   * If TRUE, enable colored output
   * If INDETERMINATE, try to autodetect if output is console
   */
  public TriBool colorMode;
  /**
   * If True, update problem_mapping.js
   */
  public boolean updateJs;
  /**
   * If > 0, run each test with a timeout
   */
  public long timeoutSeconds;
  /**
   * Number of failures, before the testing is terminated
   * If zero, testing is never terminated
   */
  public int numFailedTestsBeforeStop;
  /**
   * If True, enable solution complexity analyze
   */
  public boolean analyzeComplexity;
  /**
   * If > 0, calculate complexity with timeout
   */
  public long complexityTimeout;
  /**
   * Function for adjusting list of metric names
   * By default identity function
   * Another function may be set in programConfig callback
   */
  public Function<List<String>, List<String>> metricNamesOverride;
  /**
   * Function for adjusting list of generated metrics
   * All changes should be isomorphic to metricNamesOverride
   * By default returns identical metrics list
   * Another function may be set in programConfig callback
   */
  public BiFunction<List<Integer>, List<Object>, List<Integer>> metricsOverride;

  public TestConfig(String testFile, String testDataFile, long timeoutSeconds,
                    int numFailedTestsBeforeStop) {
    this.testFile = testFile;
    this.testDataFile = testDataFile;
    this.ttyMode = TriBool.INDETERMINATE;
    this.colorMode = TriBool.INDETERMINATE;
    this.updateJs = true;
    this.timeoutSeconds = timeoutSeconds;
    this.numFailedTestsBeforeStop = numFailedTestsBeforeStop;
    this.analyzeComplexity = false;
    this.complexityTimeout = 20;
    this.metricNamesOverride = (names) -> names;
    this.metricsOverride = (metrics, funcArgs) -> metrics;
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
        +
        "                    [--force-tty] [--no-tty] [--force-color] [--no-color]\n"
        + "\n"
        + "optional arguments:\n"
        +
        "  -h, --help                         show this help message and exit\n"
        + "  --test-data-dir [TEST_DATA_DIR]    path to test_data directory\n"
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
        config.testDataDir = getParam(commandlineArgs, ++i, "--test-data-dir");
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
      case "--no-complexity":
        config.analyzeComplexity = false;
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
