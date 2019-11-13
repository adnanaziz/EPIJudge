
package epi.test_framework.serialization_traits;

import epi.ListNode;
import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;
import java.util.ListIterator;

public class LinkedListTrait extends SerializationTrait {
  private ListTrait listTrait;

  public LinkedListTrait(SerializationTrait innerTypeTrait) {
    listTrait = new ListTrait(innerTypeTrait);
  }

  @Override
  public String name() {
    return String.format("linked_list(%s)", listTrait.getInnerTrait().name());
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    List<Object> parsed = listTrait.parse(jsonObject);
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
    }
    throw new RuntimeException("Expected ListNode");
  }

  // TODO Custom parser that throws TestFailure with mismatch info

  public SerializationTrait getInnerTrait() {
    return listTrait.getInnerTrait();
  }
}
