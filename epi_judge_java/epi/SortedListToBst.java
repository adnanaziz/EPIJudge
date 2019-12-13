package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.Iterator;
import java.util.List;
public class SortedListToBst {
  // Returns the root of the corresponding BST. The prev and next fields of the
  // list nodes are used as the BST nodes left and right fields, respectively.
  // The length of the list is given.
  public static DoublyListNode<Integer>
  buildBSTFromSortedList(DoublyListNode<Integer> l, int length) {
    // TODO - you fill in here.
    return null;
  }
  public static void compareVectorAndTree(DoublyListNode<Integer> tree,
                                          Iterator<Integer> it)
      throws TestFailure {
    if (tree == null) {
      return;
    }

    compareVectorAndTree(tree.prev, it);

    if (!it.hasNext()) {
      throw new TestFailure("Too few values in the tree");
    }
    if (it.next() != tree.data) {
      throw new TestFailure("Unexpected value");
    }

    compareVectorAndTree(tree.next, it);
  }

  @EpiTest(testDataFile = "sorted_list_to_bst.tsv")
  public static void buildBSTFromSortedListWrapper(TimedExecutor executor,
                                                   List<Integer> l)
      throws Exception {
    DoublyListNode<Integer> inputList = null;
    for (int i = l.size() - 1; i >= 0; i--) {
      inputList = new DoublyListNode<>(l.get(i), null, inputList);

      if (inputList.next != null) {
        inputList.next.prev = inputList;
      }
    }
    final DoublyListNode<Integer> finalList = inputList;
    inputList = executor.run(() -> buildBSTFromSortedList(finalList, l.size()));

    Iterator<Integer> current = l.iterator();
    compareVectorAndTree(inputList, current);
    if (current.hasNext()) {
      throw new TestFailure("Too many l in the tree");
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SortedListToBst.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
