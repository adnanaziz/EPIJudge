package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class InsertOperatorsInString {
  @EpiTest(testDataFile = "insert_operators_in_string.tsv")

  public static boolean expressionSynthesis(List<Integer> digits, int target) {

    return directedExpressionSynthesis(digits, target, 0, 0, new ArrayList<>(),
                                       new ArrayList<>());
  }

  private static boolean
  directedExpressionSynthesis(List<Integer> digits, int target, int currentTerm,
                              int offset, List<Integer> operands,
                              List<Character> operators) {
    currentTerm = currentTerm * 10 + digits.get(offset);
    if (offset == digits.size() - 1) {
      operands.add(currentTerm);
      if (evaluate(operands, operators) == target) { // Found a match.
        return true;
      }
      operands.remove(operands.size() - 1);
      return false;
    }

    // No operator.
    if (directedExpressionSynthesis(digits, target, currentTerm, offset + 1,
                                    operands, operators)) {
      return true;
    }
    // Tries multiplication operator '*'.
    operands.add(currentTerm);
    operators.add('*');
    if (directedExpressionSynthesis(digits, target, /*currentTerm=*/0,
                                    offset + 1, operands, operators)) {
      return true;
    }
    operators.remove(operators.size() - 1);
    operands.remove(operands.size() - 1);
    // Tries addition operator '+'.
    operands.add(currentTerm);
    int remainingInt = digits.subList(offset + 1, digits.size())
                           .stream()
                           .mapToInt(Integer::intValue)
                           .reduce(0, (val, d) -> val * 10 + d);
    if (target - evaluate(operands, operators) <= remainingInt) {
      operators.add('+');
      if (directedExpressionSynthesis(digits, target, /*currentTerm=*/0,
                                      offset + 1, operands, operators)) {
        return true;
      }
      operators.remove(operators.size() - 1);
    }
    operands.remove(operands.size() - 1);
    return false;
  }

  private static int evaluate(List<Integer> operands,
                              List<Character> operators) {
    Deque<Integer> intermediateOperands = new ArrayDeque<>();
    int operandIdx = 0;
    intermediateOperands.addFirst(operands.get(operandIdx++));
    // Evaluates '*' first.
    for (char oper : operators) {
      if (oper == '*') {
        intermediateOperands.addFirst(intermediateOperands.removeFirst() *
                                      operands.get(operandIdx++));
      } else {
        intermediateOperands.addFirst(operands.get(operandIdx++));
      }
    }

    // Evaluates '+' second.
    return intermediateOperands.stream().mapToInt(Integer::intValue).sum();
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "InsertOperatorsInString.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
