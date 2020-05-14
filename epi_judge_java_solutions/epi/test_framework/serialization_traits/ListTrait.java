
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class ListTrait extends SerializationTrait {
  private SerializationTrait innerTypeTrait;

  public ListTrait(SerializationTrait innerTypeTrait) {
    this.innerTypeTrait = innerTypeTrait;
  }

  @Override
  public String name() {
    return String.format("array(%s)", innerTypeTrait.name());
  }

  @Override
  public List<Object> parse(JsonValue jsonObject) {
    return StreamSupport.stream(jsonObject.asArray().spliterator(), false)
        .map(innerTypeTrait::parse)
        .collect(Collectors.toList());
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(String.format("size(%s)", argName));
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof List) {
      return Collections.singletonList(((List)x).size());
    }
    throw new RuntimeException("Expected List");
  }

  // TODO Custom parser that throws TestFailure with mismatch info

  public SerializationTrait getInnerTrait() { return innerTypeTrait; }
}
