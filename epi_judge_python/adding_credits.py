from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_failure import TestFailure


class ClientsCreditsInfo:
    def insert(self, client_id, c):
        # Implement this placeholder.
        return

    def remove(self, client_id):
        # Implement this placeholder.
        return True

    def lookup(self, client_id):
        # Implement this placeholder.
        return 0

    def add_all(self, C):
        # Implement this placeholder.
        return

    def max(self):
        # Implement this placeholder.
        return ''


def client_credits_info_tester(ops):
    cr = ClientsCreditsInfo()

    for x in ops:
        op = x[0]
        s_arg = x[1]
        i_arg = x[2]
        if op == 'ClientsCreditsInfo':
            pass
        if op == 'max':
            result = cr.max()
            if result != s_arg:
                raise TestFailure('Max: return value mismatch')
        elif op == 'remove':
            result = cr.remove(s_arg)
            if result != i_arg:
                raise TestFailure('Remove: return value mismatch')
        elif op == 'insert':
            cr.insert(s_arg, i_arg)
        elif op == "add_all":
            cr.add_all(i_arg)
        elif op == "lookup":
            result = cr.lookup(s_arg)
            if result != i_arg:
                raise TestFailure('Lookup: return value mismatch')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('adding_credits.tsv',
                                       client_credits_info_tester))
