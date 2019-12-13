
package epi;

public class BstNode<T> extends TreeLike<T, BstNode<T>> {
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
  public T getData() {
    return data;
  }

  @Override
  public BstNode<T> getLeft() {
    return left;
  }

  @Override
  public BstNode<T> getRight() {
    return right;
  }
}
