
package epi;

import epi.test_framework.BinaryTreeUtils;

import java.util.Objects;

public class BstNode<T> {
  public T data;
  public BstNode<T> left, right;

  public BstNode() {}

  public BstNode(T data) { this.data = data; }

  public BstNode(T data, BstNode<T> left, BstNode<T> right) {
    this.data = data;
    this.left = left;
    this.right = right;
  }

  @Override
  public boolean equals(Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }

    BstNode that = (BstNode)o;

    if (data != null ? !data.equals(that.data) : that.data != null) {
      return false;
    }
    if (left != null ? !left.equals(that.left) : that.left != null) {
      return false;
    }
    if (right != null ? !right.equals(that.right) : that.right != null) {
      return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    return Objects.hash(data, left, right);
  }

  @Override
  public String toString() {
    return BinaryTreeUtils.binaryTreeToString(this);
  }
}
