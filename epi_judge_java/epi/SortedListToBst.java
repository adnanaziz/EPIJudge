package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.Iterator;
import java.util.List;

public class SortedListToBst {

  // Returns the root of the corresponding BST. The prev and next fields of the
  // list nodes are used as the BST nodes left and right fields, respectively.
  // The length of the list is given.
  public static DoublyListNode<Integer>
  buildBSTFromSortedList(DoublyListNode<Integer> L, int length) {
    // Implement this placeholder.
    return null;
  }

  public static void compareVectorAndTree(DoublyListNode<Integer> tree,
                                          Iterator<Integer> it)
      throws TestFailureException {
    if (tree == null) {
      return;
    }

    compareVectorAndTree(tree.prev, it);

    if (!it.hasNext()) {
      throw new TestFailureException("Too few values in the tree");
    }
    if (it.next() != tree.data) {
      throw new TestFailureException("Unexpected value");
    }

    compareVectorAndTree(tree.next, it);
  }

  @EpiTest(testfile = "sorted_list_to_bst.tsv")
  public static void buildBSTFromSortedListWrapper(TestTimer timer,
                                                   List<Integer> L)
      throws TestFailureException {
    DoublyListNode<Integer> list = null;
    for (int i = L.size() - 1; i >= 0; i--) {
      list = new DoublyListNode<>(L.get(i), null, list);

      if (list.next != null) {
        list.next.prev = list;
      }
    }

    timer.start();
    list = buildBSTFromSortedList(list, L.size());
    timer.stop();

    Iterator<Integer> current = L.iterator();
    compareVectorAndTree(list, current);
    if (current.hasNext()) {
      throw new TestFailureException("Too many L in the tree");
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
