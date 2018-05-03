
package epi.test_framework;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * Tested function is allowed to throw this exception
 * in order to mark the current test as failed.
 */
public class TestFailure extends Exception {
  private String description;
  private List<Property> properties;

  public enum PropertyName {
    EXCEPTION_MESSAGE, // message of unhandled exception
    EXPLANATION,       // explanation from TSV file
    COMMAND,  // last command, that caused the error, in API-testing programs
    STATE,    // state of the user-defined collection (for instance, in API
              // testing)
    EXPECTED, // expected result
    RESULT,   // user-produced result
    MISSING_ITEMS,  // list of items from input that are missing in the result
                    // set
    EXCESS_ITEMS,   // list of items from result that are missing in the input
                    // set
    MISMATCH_INDEX, // for collections: index of the wrong item in result
                    // for binary trees: instance of TreePath describing the
                    // position of the wrong item
    EXPECTED_ITEM,  // value of the expected item in collection (not the whole
                    // collection)
    RESULT_ITEM     // value of the result item in collection (not the whole
                    // collection)
  }

  public class Property {
    private PropertyName name;
    private Object value;

    public Property(PropertyName name, Object value) {
      this.name = name;
      this.value = value;
    }

    public String name() {
      return name.toString().toLowerCase().replace('_', ' ');
    }

    public PropertyName rawName() { return name; }

    public int id() { return name.ordinal(); }

    public Object value() { return value; }
  }

  public TestFailure() {
    properties = new ArrayList<>();
    description = "";
  }

  public TestFailure(String description) {
    properties = new ArrayList<>();
    this.description = description;
  }

  public TestFailure withProperty(PropertyName name, Object value) {
    properties.add(new Property(name, value));
    return this;
  }

  public TestFailure withMismatchInfo(Object mismatchIndex, Object expectedItem,
                                      Object resultItem) {
    return withProperty(PropertyName.MISMATCH_INDEX, mismatchIndex)
        .withProperty(PropertyName.EXPECTED_ITEM, expectedItem)
        .withProperty(PropertyName.RESULT_ITEM, resultItem);
  }

  public String getDescription() { return description; }

  public int getMaxPropertyNameLength() {
    return properties.stream()
        .mapToInt(property -> property.name().length())
        .max()
        .orElse(0);
  }

  public List<Property> getProperties() {
    properties.sort(Comparator.comparingInt(Property::id));
    return properties;
  }
}
