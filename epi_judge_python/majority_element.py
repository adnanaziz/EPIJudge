def majority_search(stream):
    # Implement this placeholder.
    return ''


def majority_search_wrapper(stream):
    return majority_search(iter(stream))


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('majority_element.tsv',
                                   majority_search_wrapper)
