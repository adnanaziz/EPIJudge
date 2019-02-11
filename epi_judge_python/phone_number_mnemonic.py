from test_framework import generic_test, test_utils


def phone_mnemonic(phone_number):
    phone_board = ["0", "1", "ABC", "DEF", "GHI", "JKL",
        "MNO", 'PQRS', "TUV", "WXYZ",
    ]
    def dfs(start, comb, results):
        if start == n:
            results.append("".join(comb))
            return
        for c in phone_board[int(phone_number[start])]:
            comb[start] = c
            print(comb)
            dfs(start + 1, comb, results)

    results = []
    n = len(phone_number)
    comb = [0] * n
    start = 2
    dfs(0, comb, results)
    return results 


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "phone_number_mnemonic.py",
            'phone_number_mnemonic.tsv',
            phone_mnemonic,
            comparator=test_utils.unordered_compare))
