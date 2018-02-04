from test_framework.binary_tree_utils import must_find_node
from test_framework.test_utils import enable_timer_hook


def pair_includes_ancestor_and_descendant_of_m(possible_anc_or_desc_0,
                                               possible_anc_or_desc_1, middle):
    # Implement this placeholder.
    return True


@enable_timer_hook
def pair_includes_ancestor_and_descendant_of_m_wrapper(
        timer, tree, possible_anc_or_desc_0, possible_anc_or_desc_1,
        middle_idx):
    candidate0 = must_find_node(tree, possible_anc_or_desc_0)
    candidate1 = must_find_node(tree, possible_anc_or_desc_1)
    middle_node = must_find_node(tree, middle_idx)

    timer.start()
    result = pair_includes_ancestor_and_descendant_of_m(
        candidate0, candidate1, middle_node)
    timer.stop()
    return result


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        'descendant_and_ancestor_in_bst.tsv',
        pair_includes_ancestor_and_descendant_of_m_wrapper)
