// @library
package epi.test_framework;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Objects;

public class TestConfig {
  public String testDataDir;
  public String testDataFile;
  public Boolean stopOnError;
  public int timeout;

  public TestConfig(String testDataDir, String testDataFile,
                    Boolean stopOnError, int timeout) {
    this.testDataDir = testDataDir;
    this.testDataFile = testDataFile;
    this.stopOnError = stopOnError;
    this.timeout = timeout;
  }

  public static TestConfig fromCommandLine(String testDataFile,
                                           String[] commandlineArgs) {
    TestConfig config = new TestConfig("", testDataFile, true, 0);

    for (int i = 0; i < commandlineArgs.length; i++) {
      if (Objects.equals(commandlineArgs[i], "--test_data_dir")) {
        if (i + 1 >= commandlineArgs.length) {
          throw new RuntimeException("Missing param for --test_data_dir");
        }
        config.testDataDir = commandlineArgs[i + 1];
        i++;
      } else if (Objects.equals(commandlineArgs[i], "--run_all_tests")) {
        config.stopOnError = false;
      } else {
        throw new RuntimeException("Unrecognized argument: " +
                                   commandlineArgs[i]);
      }
    }

    if (config.testDataDir != null && !config.testDataDir.isEmpty()) {
      if (!Files.isDirectory(Paths.get(config.testDataDir))) {
        throw new RuntimeException("--test_data_dir argument \"" +
                                   config.testDataDir +
                                   "\" is not a directory");
      }
    } else {
      config.testDataDir = TestUtils.getDefaultTestDataDirPath();
    }

    return config;
  }
}
