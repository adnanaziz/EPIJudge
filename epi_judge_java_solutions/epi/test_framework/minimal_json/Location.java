
package epi.test_framework.minimal_json;

/**
 * An immutable object that represents a location in the parsed text.
 */
class Location {
  /**
   * The absolute character index, starting at 0.
   */
  public final int offset;

  /**
   * The line number, starting at 1.
   */
  public final int line;

  /**
   * The column number, starting at 1.
   */
  public final int column;

  Location(int offset, int line, int column) {
    this.offset = offset;
    this.column = column;
    this.line = line;
  }

  @Override
  public String toString() {
    return line + ":" + column;
  }

  @Override
  public int hashCode() {
    return offset;
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) {
      return true;
    }
    if (obj == null) {
      return false;
    }
    if (getClass() != obj.getClass()) {
      return false;
    }
    Location other = (Location)obj;
    return offset == other.offset && column == other.column &&
        line == other.line;
  }
}
