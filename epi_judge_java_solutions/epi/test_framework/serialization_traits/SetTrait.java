
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class SetTrait extends SerializationTrait {
  private ListTrait listTrait;

  public SetTrait(SerializationTrait innerTypeTrait) {
    listTrait = new ListTrait(innerTypeTrait);
  }

  @Override
  public String name() {
    return String.format("set(%s)", listTrait.getInnerTrait().name());
  }

  @Override
  public HashSet<Object> parse(JsonValue jsonObject) {
    return new HashSet<>(listTrait.parse(jsonObject));
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(String.format("size(%s)", argName));
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Set) {
      return Collections.singletonList(((Set)x).size());
    }
    throw new RuntimeException("Expected Set");
  }

  // TODO: Custom parser that throws TestFailure with mismatch info

  public SerializationTrait getInnerTrait() {
    return listTrait.getInnerTrait();
  }
}
