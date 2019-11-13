
package epi;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ListNode<T> {
  public T data;
  public ListNode<T> next;

  public ListNode(T data, ListNode<T> next) {
    this.data = data;
    this.next = next;
  }

  public List<T> toArray() {
    List<T> result = new ArrayList<>();
    ListNode<T> iter = this;
    while (iter != null) {
      result.add(iter.data);
      iter = iter.next;
    }
    return result;
  }

  @Override
  public String toString() {
    StringBuilder result = new StringBuilder();
    Set<ListNode<T>> visited = new HashSet<ListNode<T>>();
    ListNode<T> node = this;
    boolean first = true;

    while (node != null) {
      if (first) {
        first = false;
      } else {
        result.append(" -> ");
      }
      if (visited.contains(node)) {
        if (node.next != node) {
          result.append(node.data == null ? "null" : node.data.toString())
              .append(" -> ... -> ");
        }
        result.append(node.data == null ? "null" : node.data.toString())
            .append(" -> ...");
        break;
      } else {
        result.append(node.data == null ? "null" : node.data.toString());
        visited.add(node);
        node = node.next;
      }
    }
    return result.toString();
  }

  @Override
  public boolean equals(Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }

    ListNode<?> that = (ListNode<?>)o;

    return equalsIterativeImpl(this, that);
  }

  public static boolean equalsIterativeImpl(ListNode<?> a, ListNode<?> b) {
    Set<ListNode<?>> visitedA = new HashSet<ListNode<?>>();
    Set<ListNode<?>> visitedB = new HashSet<ListNode<?>>();

    while (a != null && b != null) {
      if (visitedA.contains(a)) {
        return a.data.equals(b.data) && visitedB.contains(b);
      }
      if (!a.data.equals(b.data)) {
        return false;
      }
      visitedA.add(a);
      visitedB.add(b);
      a = a.next;
      b = b.next;
    }
    return a == null && b == null;
  }

  // TODO: Factor out this function like C++ and Python by taking a parameter.
  public int size() {
    int result = 0;
    Set<ListNode<T>> visited = new HashSet<ListNode<T>>();
    ListNode<T> node = this;

    while (node != null && !visited.contains(node)) {
      result++;
      visited.add(node);
      node = node.next;
    }
    return result;
  }
}
