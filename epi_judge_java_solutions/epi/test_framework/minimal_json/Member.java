
package epi.test_framework.minimal_json;

/**
 * Represents a member of a JSON object, a pair of a name and a value.
 */
public class Member {
  private final String name;
  private final JsonValue value;

  Member(String name, JsonValue value) {
    this.name = name;
    this.value = value;
  }

  /**
   * Returns the name of this member.
   *
   * @return the name of this member, never <code>null</code>
   */
  public String getName() { return name; }

  /**
   * Returns the value of this member.
   *
   * @return the value of this member, never <code>null</code>
   */
  public JsonValue getValue() { return value; }

  @Override
  public int hashCode() {
    int result = 1;
    result = 31 * result + name.hashCode();
    result = 31 * result + value.hashCode();
    return result;
  }

  /**
   * Indicates whether a given object is "equal to" this JsonObject. An object
   * is considered equal
   * if it is also a <code>JsonObject</code> and both objects contain the same
   * members <em>in
   * the same order</em>.
   * <p>
   * If two JsonObjects are equal, they will also produce the same JSON output.
   * </p>
   *
   * @param object
   *          the object to be compared with this JsonObject
   * @return <tt>true</tt> if the specified object is equal to this JsonObject,
   * <code>false</code>
   *         otherwise
   */
  @Override
  public boolean equals(Object object) {
    if (this == object) {
      return true;
    }
    if (object == null) {
      return false;
    }
    if (getClass() != object.getClass()) {
      return false;
    }
    Member other = (Member)object;
    return name.equals(other.name) && value.equals(other.value);
  }
}
