package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CopyPostingList {

  public static PostingListNode copyPostingsList(PostingListNode l) {

    if (l == null) {
      return null;
    }

    // Stage 1: Makes a copy of the original list without assigning the jump
    //          field, and creates the mapping for each node in the original
    //          list to the copied list.
    PostingListNode iter = l;
    while (iter != null) {
      PostingListNode newNode =
          new PostingListNode(iter.order, iter.next, null);
      iter.next = newNode;
      iter = newNode.next;
    }

    // Stage 2: Assigns the jump field in the copied list.
    iter = l;
    while (iter != null) {
      if (iter.jump != null) {
        iter.next.jump = iter.jump.next;
      }
      iter = iter.next.next;
    }

    // Stage 3: Reverts the original list, and assigns the next field of
    //          the copied list.
    iter = l;
    PostingListNode newListHead = iter.next;
    while (iter.next != null) {
      PostingListNode temp = iter.next;
      iter.next = temp.next;
      iter = temp;
    }
    return newListHead;
  }

  @EpiUserType(ctorParams = {int.class, int.class})
  public static class SerializedNode {
    public int order;
    public int jumpIndex;

    public SerializedNode(int order, int jumpIndex) {
      this.order = order;
      this.jumpIndex = jumpIndex;
    }
  }

  public static PostingListNode
  createPostingList(List<SerializedNode> serialized) {
    Map<Integer, PostingListNode> keyMapping = new HashMap<>();
    PostingListNode head = null;
    for (int i = serialized.size() - 1; i >= 0; i--) {
      head = new PostingListNode(serialized.get(i).order, head, null);
      keyMapping.put(head.order, head);
    }
    PostingListNode listIt = head;
    for (SerializedNode x : serialized) {
      if (x.jumpIndex != -1) {
        listIt.jump = keyMapping.get(x.jumpIndex);
        if (listIt.jump == null) {
          throw new RuntimeException("Jump index out of range");
        }
      }
    }

    return head;
  }

  public static void assertListsEqual(PostingListNode orig,
                                      PostingListNode copy) throws TestFailure {
    Map<PostingListNode, PostingListNode> nodeMapping = new HashMap<>();
    PostingListNode oIt = orig;
    PostingListNode cIt = copy;

    int idx = 0;

    while (oIt != null) {
      if (cIt == null) {
        throw new TestFailure("Copied list has fewer nodes than the original")
            .withProperty(TestFailure.PropertyName.EXPECTED, orig)
            .withProperty(TestFailure.PropertyName.RESULT, copy)
            .withProperty(TestFailure.PropertyName.MISSING_ITEMS, oIt);
      }
      if (oIt.order != cIt.order) {
        throw new TestFailure()
            .withProperty(TestFailure.PropertyName.EXPECTED, orig)
            .withProperty(TestFailure.PropertyName.RESULT, copy)
            .withMismatchInfo(idx, oIt.order, cIt.order);
      }
      nodeMapping.put(oIt, cIt);
      oIt = oIt.next;
      cIt = cIt.next;
      idx++;
    }

    if (cIt != null) {
      throw new TestFailure("Copied list has fewer nodes than the original")
          .withProperty(TestFailure.PropertyName.EXPECTED, orig)
          .withProperty(TestFailure.PropertyName.RESULT, copy)
          .withProperty(TestFailure.PropertyName.EXCESS_ITEMS, cIt);
    }

    oIt = orig;
    cIt = copy;
    idx = 0;
    while (oIt != null) {
      if (nodeMapping.get(cIt) != null) {
        throw new TestFailure(
            "Copied list contains a node from the original list")
            .withProperty(TestFailure.PropertyName.EXPECTED, orig)
            .withProperty(TestFailure.PropertyName.RESULT, copy)
            .withProperty(TestFailure.PropertyName.MISMATCH_INDEX, idx)
            .withProperty(TestFailure.PropertyName.RESULT_ITEM,
                          new PostingListNode(cIt.order, null, null));
      }
      if (oIt.jump != null) {
        if (nodeMapping.get(oIt.jump) != cIt.jump) {
          throw new TestFailure(
              "Jump link points to a different nodes in the copied list")
              .withProperty(TestFailure.PropertyName.EXPECTED, orig)
              .withProperty(TestFailure.PropertyName.RESULT, copy)
              .withMismatchInfo(idx, oIt, cIt);
        }
      } else {
        if (cIt.jump != null) {
          throw new TestFailure(
              "Jump link points to a different nodes in the copied list")
              .withProperty(TestFailure.PropertyName.EXPECTED, orig)
              .withProperty(TestFailure.PropertyName.RESULT, copy)
              .withMismatchInfo(idx, oIt, cIt);
        }
      }
      oIt = oIt.next;
      cIt = cIt.next;
      idx++;
    }
  }

  @EpiTest(testDataFile = "copy_posting_list.tsv")
  public static void copyPostingsListWrapper(TimedExecutor executor,
                                             List<SerializedNode> l)
      throws Exception {
    PostingListNode head = createPostingList(l);

    PostingListNode copy = executor.run(() -> copyPostingsList(head));

    assertListsEqual(head, copy);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "CopyPostingList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
