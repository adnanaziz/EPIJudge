
package epi;

public class PostingListNode {
  public int order;
  public PostingListNode next, jump;

  public PostingListNode(int order, PostingListNode next,
                         PostingListNode jump) {
    this.order = order;
    this.next = next;
    this.jump = jump;
  }
}
