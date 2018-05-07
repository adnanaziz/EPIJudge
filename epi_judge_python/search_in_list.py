from test_framework import generic_test


def search_list(L, key):
    # TODO - you fill in here.
    return None


def search_list_wrapper(L, key):
    result = search_list(L, key)
    return result.data if result else -1


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "search_in_list.py", 'search_in_list.tsv', search_list_wrapper))
