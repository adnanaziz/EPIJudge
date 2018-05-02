from test_framework import generic_test


def levenshtein_distance(A, B):
    def compute_distance_between_prefixes(A_idx, B_idx):
        if A_idx < 0:
            # A is empty so add all of B's characters.
            return B_idx + 1
        elif B_idx < 0:
            # B is empty so delete all of A's characters.
            return A_idx + 1
        if distance_between_prefixes[A_idx][B_idx] == -1:
            if A[A_idx] == B[B_idx]:
                distance_between_prefixes[A_idx][B_idx] = (
                    compute_distance_between_prefixes(A_idx - 1, B_idx - 1))
            else:
                substitute_last = compute_distance_between_prefixes(
                    A_idx - 1, B_idx - 1)
                add_last = compute_distance_between_prefixes(A_idx - 1, B_idx)
                delete_last = compute_distance_between_prefixes(
                    A_idx, B_idx - 1)
                distance_between_prefixes[A_idx][B_idx] = (
                    1 + min(substitute_last, add_last, delete_last))
        return distance_between_prefixes[A_idx][B_idx]

    distance_between_prefixes = [[-1] * len(B) for _ in A]
    return compute_distance_between_prefixes(len(A) - 1, len(B) - 1)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("levenshtein_distance.py",
                                       "levenshtein_distance.tsv",
                                       levenshtein_distance))
