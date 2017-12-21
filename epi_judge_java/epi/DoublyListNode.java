
package epi;

public class DoublyListNode<T> {
  public T data;
  public DoublyListNode<T> prev, next;

  DoublyListNode(T data, DoublyListNode<T> prev, DoublyListNode<T> next) {
    this.data = data;
    this.prev = prev;
    this.next = next;
  }
}
