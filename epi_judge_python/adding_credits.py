from test_framework import generic_test
from test_framework.test_failure import TestFailure


class ClientsCreditsInfo:
    def insert(self, client_id, c):
        # TODO - you fill in here.
        return

    def remove(self, client_id):
        # TODO - you fill in here.
        return True

    def lookup(self, client_id):
        # TODO - you fill in here.
        return 0

    def add_all(self, C):
        # TODO - you fill in here.
        return

    def max(self):
        # TODO - you fill in here.
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
        generic_test.generic_test_main("adding_credits.py",
                                       'adding_credits.tsv',
                                       client_credits_info_tester))
