from test_framework import generic_test


def num_combinations_for_final_score(final_score, individual_play_scores):
    A = [[0] * (final_score + 1) for _ in individual_play_scores]
    for r in A:
        r[0] = 1
    for i in range(len(A)):
        for j in range(1, final_score + 1):
            without_play = A[i-1][j] if i > 0 else 0
            with_play = A[i][j-individual_play_scores[i]] if j >= individual_play_scores[i] else 0
            A[i][j] = without_play + with_play
    return A[-1][-1]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("number_of_score_combinations.py",
                                       "number_of_score_combinations.tsv",
                                       num_combinations_for_final_score))
