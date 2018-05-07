
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class SetTraits extends SerializationTraits {
  private ListTraits listTraits;

  public SetTraits(SerializationTraits innerTypeTraits) {
    listTraits = new ListTraits(innerTypeTraits);
  }

  @Override
  public String name() {
    return String.format("set(%s)", listTraits.getInnerTraits().name());
  }

  @Override
  public HashSet<Object> parse(String str) {
    return new HashSet<>(listTraits.parse(str));
  }

  @Override
  public HashSet<Object> jsonParse(JsonValue jsonObject) {
    return new HashSet<>(listTraits.jsonParse(jsonObject));
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(String.format("size(%s)", argName));
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Set) {
      return Collections.singletonList(((Set)x).size());
    } else {
      throw new RuntimeException("Expected Set");
    }
  }

  // TODO Custom parser that throws TestFailure with mismatch info

  public SerializationTraits getInnerTraits() {
    return listTraits.getInnerTraits();
  }
}
