
package epi.test_framework;

public enum TriBool {
  FALSE,
  TRUE,
  INDETERMINATE;

  public boolean getOrDefault(boolean defaultValue) {
    switch (this) {
    case FALSE:
      return false;
    case TRUE:
      return true;
    case INDETERMINATE:
    default:
      return defaultValue;
    }
  }
}
