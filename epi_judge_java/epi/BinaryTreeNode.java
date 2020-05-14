
package epi;

public class BinaryTreeNode<T> extends TreeLike<T, BinaryTreeNode<T>> {
  public T data;
  public BinaryTreeNode<T> left, right;

  public BinaryTreeNode() {}

  public BinaryTreeNode(T data) { this.data = data; }

  public BinaryTreeNode(T data, BinaryTreeNode<T> left,
                        BinaryTreeNode<T> right) {
    this.data = data;
    this.left = left;
    this.right = right;
  }

  @Override
  public T getData() {
    return data;
  }

  @Override
  public BinaryTreeNode<T> getLeft() {
    return left;
  }

  @Override
  public BinaryTreeNode<T> getRight() {
    return right;
  }
}
