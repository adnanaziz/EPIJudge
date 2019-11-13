package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.PriorityQueue;

public class HuffmanCoding {
  @EpiUserType(ctorParams = {String.class, double.class})

  public static class CharWithFrequency {
    public char c;
    public double freq;
    public String code;

    public CharWithFrequency(String s, double freq) {
      if (s.length() != 1) {
        throw new RuntimeException(
            "CharWithFrequency parser: string length is not 1");
      }
      this.c = s.charAt(0);
      this.freq = freq;
    }
  }

  public static class BinaryTree implements Comparable<BinaryTree> {
    public double aggregateFreq;
    public CharWithFrequency s;
    public BinaryTree left, right;

    public BinaryTree(double aggregateFreq, CharWithFrequency s,
                      BinaryTree left, BinaryTree right) {
      this.aggregateFreq = aggregateFreq;
      this.s = s;
      this.left = left;
      this.right = right;
    }

    @Override
    public int compareTo(BinaryTree o) {
      return Double.compare(aggregateFreq, o.aggregateFreq);
    }

    @Override
    public boolean equals(Object obj) {
      if (obj == null || !(obj instanceof BinaryTree)) {
        return false;
      }
      return this == obj ? true
                         : aggregateFreq == ((BinaryTree)obj).aggregateFreq;
    }

    @Override
    public int hashCode() {
      return Objects.hash(aggregateFreq);
    }
  }

  @EpiTest(testDataFile = "huffman_coding.tsv")

  public static Double huffmanEncoding(List<CharWithFrequency> symbols) {

    PriorityQueue<BinaryTree> candidates = new PriorityQueue<>();
    // Add leaves for symbols.
    for (CharWithFrequency s : symbols) {
      candidates.add(new BinaryTree(s.freq, s, null, null));
    }

    // Keeps combining two nodes until there is one node left, which is the
    // root.
    while (candidates.size() > 1) {
      BinaryTree left = candidates.remove();
      BinaryTree right = candidates.remove();
      candidates.add(new BinaryTree(left.aggregateFreq + right.aggregateFreq,
                                    null, left, right));
    }

    Map<Character, String> charToEncoding = new HashMap<>();
    // Traverses the binary tree, assigning codes to nodes.
    assignHuffmanCode(candidates.peek(), new StringBuilder(), charToEncoding);
    return symbols.stream()
        .mapToDouble(s -> charToEncoding.get(s.c).length() * s.freq / 100.0)
        .sum();
  }

  private static void assignHuffmanCode(BinaryTree tree, StringBuilder code,
                                        Map<Character, String> charToEncoding) {
    if (tree != null) {
      if (tree.s != null) {
        // This node is a leaf.
        charToEncoding.put(tree.s.c, code.toString());
      } else { // Non-leaf node.
        code.append('0');
        assignHuffmanCode(tree.left, code, charToEncoding);
        code.setLength(code.length() - 1);
        code.append('1');
        assignHuffmanCode(tree.right, code, charToEncoding);
        code.setLength(code.length() - 1);
      }
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "HuffmanCoding.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
