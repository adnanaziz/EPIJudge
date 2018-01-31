def majority_search(stream):
    # Implement this placeholder.
    return ''


def majority_search_wrapper(stream):
    return majority_search(iter(stream))


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('majority_element.tsv',
                                              majority_search_wrapper)
