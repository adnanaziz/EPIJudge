package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class TreeFromPreorderInorder {
  @EpiTest(testDataFile = "tree_from_preorder_inorder.tsv")

  public static BinaryTreeNode<Integer>
  binaryTreeFromPreorderInorder(List<Integer> preorder, List<Integer> inorder) {

    return binaryTreeFromPreorderInorderHelper(
        preorder, /*preorderStart=*/0, preorder.size(), /*inorderStart=*/0,
        inorder.size(),
        IntStream.range(0, inorder.size())
            .boxed()
            .collect(Collectors.toMap(i -> inorder.get(i), i -> i)));
  }

  // Builds the subtree with preorder.subList(preorderStart, preorderEnd) and
  // inorder.subList(inorderStart, inorderEnd).
  private static BinaryTreeNode<Integer>
  binaryTreeFromPreorderInorderHelper(List<Integer> preorder, int preorderStart,
                                      int preorderEnd, int inorderStart,
                                      int inorderEnd,
                                      Map<Integer, Integer> nodeToInorderIdx) {
    if (preorderEnd <= preorderStart || inorderEnd <= inorderStart) {
      return null;
    }
    int rootInorderIdx = nodeToInorderIdx.get(preorder.get(preorderStart));
    int leftSubtreeSize = rootInorderIdx - inorderStart;

    return new BinaryTreeNode<>(
        preorder.get(preorderStart),
        // Recursively builds the left subtree.
        binaryTreeFromPreorderInorderHelper(
            preorder, preorderStart + 1, preorderStart + 1 + leftSubtreeSize,
            inorderStart, rootInorderIdx, nodeToInorderIdx),
        // Recursively builds the right subtree.
        binaryTreeFromPreorderInorderHelper(
            preorder, preorderStart + 1 + leftSubtreeSize, preorderEnd,
            rootInorderIdx + 1, inorderEnd, nodeToInorderIdx));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreeFromPreorderInorder.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
