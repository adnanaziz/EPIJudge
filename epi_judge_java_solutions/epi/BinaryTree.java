
package epi;

import epi.test_framework.BinaryTreeUtils;

public class BinaryTree<T> {
  public T data;
  public BinaryTree<T> left, right;
  public BinaryTree<T> parent;

  public BinaryTree() {}

  public BinaryTree(T data) { this.data = data; }

  public BinaryTree(T data, BinaryTree<T> left, BinaryTree<T> right) {
    this.data = data;
    this.left = left;
    this.right = right;
  }

  public BinaryTree(T data, BinaryTree<T> left, BinaryTree<T> right,
                    BinaryTree<T> parent) {
    this(data, left, right);
    this.parent = parent;
  }

  @Override
  public String toString() {
    return BinaryTreeUtils.binaryTreeToString(this);
  }
}
