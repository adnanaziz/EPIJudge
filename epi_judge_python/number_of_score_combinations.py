def num_combinations_for_final_score(final_score, individual_play_scores):
    # Implement this placeholder.
    return 0


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("number_of_score_combinations.tsv",
                                       num_combinations_for_final_score))
