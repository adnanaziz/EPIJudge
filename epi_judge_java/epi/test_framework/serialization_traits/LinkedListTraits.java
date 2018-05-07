
package epi.test_framework.serialization_traits;

import epi.ListNode;
import epi.test_framework.minimal_json.Json;
import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;
import java.util.ListIterator;

public class LinkedListTraits extends SerializationTraits {
  private ListTraits listTraits;

  public LinkedListTraits(SerializationTraits innerTypeTraits) {
    listTraits = new ListTraits(innerTypeTraits);
  }

  @Override
  public String name() {
    return String.format("linked_list(%s)", listTraits.getInnerTraits().name());
  }

  @Override
  public Object parse(String str) {
    return jsonParse(Json.parse(str));
  }

  @Override
  public Object jsonParse(JsonValue jsonObject) {
    List<Object> parsed = listTraits.jsonParse(jsonObject);
    ListNode<Object> head = null;
    ListIterator<Object> valuesIt = parsed.listIterator(parsed.size());
    while (valuesIt.hasPrevious()) {
      head = new ListNode<>(valuesIt.previous(), head);
    }
    return head;
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(String.format("size(%s)", argName));
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x == null) {
      return Collections.singletonList(0);
    } else if (x instanceof ListNode) {
      return Collections.singletonList(((ListNode)x).size());
    } else {
      throw new RuntimeException("Expected ListNode");
    }
  }

  // TODO Custom parser that throws TestFailure with mismatch info

  public SerializationTraits getInnerTraits() {
    return listTraits.getInnerTraits();
  }
}
