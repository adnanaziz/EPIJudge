from test_framework.binary_tree_utils import must_find_node
from test_framework.test_utils import enable_timer_hook


def pair_includes_ancestor_and_descendant_of_m(possible_anc_or_desc_0,
                                               possible_anc_or_desc_1, middle):
    # Implement this placeholder.
    return True


@enable_timer_hook
def pair_includes_ancestor_and_descendant_of_m_wrapper(
        timer, tree, candidate1_idx, candidate2_idx, middle_idx):
    candidate1 = must_find_node(tree, candidate1_idx)
    candidate2 = must_find_node(tree, candidate2_idx)
    middle = must_find_node(tree, middle_idx)

    timer.start()
    result = pair_includes_ancestor_and_descendant_of_m(
        candidate1, candidate2, middle)
    timer.stop()
    return result


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'descendant_and_ancestor_in_bst.tsv',
        pair_includes_ancestor_and_descendant_of_m_wrapper)
