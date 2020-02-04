from typing import List

from test_framework import generic_test


def multiply(num1: List[int], num2: List[int]) -> List[int]:
    num1str, num2str = "", ""
    result = []
    for n in num1: num1str += str(n)
    for n in num2: num2str += str(n)
    resultnum = str(int(num1str) * int(num2str))
    if resultnum[0] == "-":
        negNum = resultnum[1:]
        for ind, n in enumerate(negNum):
            if ind == 0:
                result.append(-int(n))
            else:
                result.append(int(n))
    else:
        for n in resultnum:
            result.append(int(n))
    return result

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('int_as_array_multiply.py',
                                       'int_as_array_multiply.tsv', multiply))
