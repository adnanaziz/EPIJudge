# Finds the candidates which may occur > n / k times.
def search_frequent_items(k, stream):
    # Implement this placeholder.
    return []


def search_frequent_items_wrapper(k, stream):
    return search_frequent_items(k, iter(stream))


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main("search_frequent_items.tsv",
                                              search_frequent_items_wrapper,
                                              test_utils.unordered_compare)
