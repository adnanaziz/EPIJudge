package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CopyPostingList {
  public static PostingListNode copyPostingsList(PostingListNode L) {
    // Implement this placeholder.
    return null;
  }

  @EpiUserType(ctorParams = {int.class, int.class})
  public static class SerializedNode {
    public int order;
    public int jump_index;

    public SerializedNode(int order, int jump_index) {
      this.order = order;
      this.jump_index = jump_index;
    }
  }

  public static PostingListNode createPostingList(List<SerializedNode> serialized) {
    Map<Integer, PostingListNode> keyMapping = new HashMap<>();
    PostingListNode head = null;
    for (int i = serialized.size() - 1; i >= 0; i--) {
      head = new PostingListNode(serialized.get(i).order, head, null);
      keyMapping.put(head.order, head);
    }
    PostingListNode list_it = head;
    for (SerializedNode x : serialized) {
      if (x.jump_index != -1) {
        list_it.jump = keyMapping.get(x.jump_index);
        if (list_it.jump == null) {
          throw new RuntimeException("Jump index out of range");
        }
      }
    }

    return head;
  }

  public static void assertListsEqual(PostingListNode orig, PostingListNode copy)
      throws TestFailureException {
    Map<PostingListNode, PostingListNode> nodeMapping = new HashMap<>();
    PostingListNode oIt = orig;
    PostingListNode cIt = copy;

    while (oIt != null) {
      if (cIt == null) {
        throw new TestFailureException("Copied list has fewer nodes than the original");
      }
      if (oIt.order != cIt.order) {
        throw new TestFailureException("Order value mismatch");
      }
      nodeMapping.put(oIt, cIt);
      oIt = oIt.next;
      cIt = cIt.next;
    }

    if (cIt != null) {
      throw new TestFailureException("Copied list has more nodes than the original");
    }

    oIt = orig;
    cIt = copy;

    while (oIt != null) {
      if (nodeMapping.get(cIt) != null) {
        throw new TestFailureException("Copied list contains a node from the original list");
      }
      if (oIt.jump != null) {
        if (nodeMapping.get(oIt.jump) != cIt.jump) {
          throw new TestFailureException(
              "Jump link points to a different nodes in the copied list");
        }
      } else {
        if (cIt.jump != null) {
          throw new TestFailureException(
              "Jump link points to a different nodes in the copied list");
        }
      }
      oIt = oIt.next;
      cIt = cIt.next;
    }
  }

  @EpiTest(testfile = "copy_posting_list.tsv")
  public static void copyPostingsListWrapper(TestTimer timer, List<SerializedNode> serializedNodes)
      throws TestFailureException {
    PostingListNode head = createPostingList(serializedNodes);

    timer.start();
    PostingListNode copy = copyPostingsList(head);
    timer.stop();

    assertListsEqual(head, copy);
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
