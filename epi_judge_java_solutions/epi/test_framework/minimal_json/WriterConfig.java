
package epi.test_framework.minimal_json;

import java.io.Writer;

/**
 * Controls the formatting of the JSON output. Use one of the available
 * constants.
 */
public abstract class WriterConfig {
  /**
   * Write JSON in its minimal form, without any additional whitespace. This is
   * the default.
   */
  public static WriterConfig MINIMAL = new WriterConfig() {
    @Override
    JsonWriter createWriter(Writer writer) {
      return new JsonWriter(writer);
    }
  };

  /**
   * Write JSON in pretty-print, with each value on a separate line and an
   * indentation of two
   * spaces.
   */
  public static WriterConfig PRETTY_PRINT = PrettyPrint.indentWithSpaces(4);

  abstract JsonWriter createWriter(Writer writer);
}
