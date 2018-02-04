from list_node import ListNode


def search_list(L, key):
    # Implement this placeholder.
    return None


def search_list_wrapper(L, key):
    result = search_list(L, key)
    return result.data if result else -1


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('search_in_list.tsv', search_list_wrapper)
