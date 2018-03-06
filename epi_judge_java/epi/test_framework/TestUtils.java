// @library
package epi.test_framework;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Stream;

public class TestUtils {
  public static List<List<String>> splitTsvFile(Path tsvFile) {
    final String FIELD_DELIM = "\t";

    Stream<String> inputData = null;
    try {
      inputData = Files.lines(tsvFile);
    } catch (IOException e) {
      throw new RuntimeException("Test data file not found");
    }

    List<String> asList =
        inputData.collect(ArrayList::new, ArrayList::add, ArrayList::addAll);

    List<List<String>> result = new ArrayList<>();
    for (String line : asList) {
      result.add(Arrays.asList(line.split(FIELD_DELIM)));
    }
    return result;
  }

  public static String getDefaultTestDataDirPath() {
    final int MAX_SEARCH_DEPTH = 4;
    final String ENV_KEY = "EPI_TEST_DATA_DIR";
    final String DIR_NAME = "test_data";

    String env_result = System.getenv(ENV_KEY);
    if (env_result != null && !env_result.isEmpty()) {
      if (!Files.isDirectory(Paths.get(env_result))) {
        throw new RuntimeException(ENV_KEY +
                                   " environment variable is set to \"" +
                                   env_result + "\", but it's not a directory");
      }
      return env_result;
    }

    Path path = Paths.get(".").toAbsolutePath();
    for (int i = 0; i < MAX_SEARCH_DEPTH; i++) {
      if (Files.isDirectory(path.resolve(DIR_NAME))) {
        return path.resolve(DIR_NAME).toString();
      }
      path = path.getParent();
      if (path == null) {
        break;
      }
    }

    throw new RuntimeException(
        "Can't find test data directory. Specify it with " + ENV_KEY +
        " environment variable (you may need to restart PC) or start the program with \"--test_data_dir <path>\" command-line option");
  }

  /**
   * Serialized type name can contain multiple comments, enclosed into brackets.
   * This method removes all such comments.
   */
  public static String filterBracketComments(String s) {
    final String BRACKET_ENCLOSED_COMMENT = "(\\[[^\\]]*\\])";
    return s.replaceAll(BRACKET_ENCLOSED_COMMENT, "").replaceAll(" ", "");
  }

  /**
   * Check that result list has the same count of elements as reference.
   * TestFailure is thrown in case of mismatch.
   */
  public static <T> void assertAllValuesPresent(List<T> reference,
                                                List<T> result)
      throws TestFailure {
    Map<T, Integer> referenceSet = new HashMap<>();
    for (T x : reference) {
      referenceSet.put(x, referenceSet.getOrDefault(x, 0) + 1);
    }

    for (T x : result) {
      referenceSet.put(x, referenceSet.getOrDefault(x, 0) - 1);
    }

    List<T> excessItems = new ArrayList<>();
    List<T> missingItems = new ArrayList<>();

    referenceSet.forEach((x, count) -> {
      if (count < 0) {
        while (count++ < 0) {
          excessItems.add(x);
        }
      } else if (count > 0) {
        while (count-- > 0) {
          missingItems.add(x);
        }
      }
    });

    if (!excessItems.isEmpty() || !missingItems.isEmpty()) {
      TestFailure e =
          new TestFailure("Value set changed")
              .withProperty(TestFailure.PropertyName.RESULT, result);
      if (!excessItems.isEmpty()) {
        e.withProperty(TestFailure.PropertyName.EXCESS_ITEMS, excessItems);
      }
      if (!missingItems.isEmpty()) {
        e.withProperty(TestFailure.PropertyName.MISSING_ITEMS, missingItems);
      }
      throw e;
    }
  }

  /**
   * Non-exact float comparison
   */
  public static boolean floatComparison(Float f1, Float f2) {
    float eps = 1E-4f;
    return Math.abs(f1 - f2) <= eps * Math.max(Math.abs(f1), Math.abs(f2));
  }

  /**
   * Non-exact double comparison
   */
  public static boolean doubleComparison(Double d1, Double d2) {
    double eps = 1E-6;
    return Math.abs(d1 - d2) <= eps * Math.max(Math.abs(d1), Math.abs(d2));
  }
}
