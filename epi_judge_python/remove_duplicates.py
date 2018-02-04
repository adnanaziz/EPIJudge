from test_framework.test_utils import enable_timer_hook


class Name:
    def __init__(self, first_name, last_name):
        self.first_name, self.last_name = first_name, last_name

    def __lt__(self, other):
        return (self.first_name < other.first_name
                if self.first_name != other.first_name else
                self.last_name < other.last_name)


def eliminate_duplicate(A):
    # Implement this placeholder.
    return


@enable_timer_hook
def eliminate_duplicate_wrapper(timer, names):
    names = [Name(*x) for x in names]

    timer.start()
    eliminate_duplicate(names)
    timer.stop()

    return names


def comp(expected, result):
    return all([
        e == r.first_name for (e, r) in zip(sorted(expected), sorted(result))
    ])


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('remove_duplicates.tsv',
                                   eliminate_duplicate_wrapper, comp)
