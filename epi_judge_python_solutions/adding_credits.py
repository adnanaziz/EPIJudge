import bintrees

from test_framework import generic_test
from test_framework.test_failure import TestFailure


class ClientsCreditsInfo:
    def __init__(self):
        self._offset = 0
        self._client_to_credit = {}
        self._credit_to_clients = bintrees.RBTree()

    def insert(self, client_id, c):

        self.remove(client_id)
        self._client_to_credit[client_id] = c - self._offset
        self._credit_to_clients.setdefault(c - self._offset,
                                           set()).add(client_id)

    def remove(self, client_id):

        credit = self._client_to_credit.get(client_id)
        if credit is not None:
            self._credit_to_clients[credit].remove(client_id)
            if not self._credit_to_clients[credit]:
                del self._credit_to_clients[credit]
            del self._client_to_credit[client_id]
            return True
        return False

    def lookup(self, client_id):

        credit = self._client_to_credit.get(client_id)
        return -1 if credit is None else credit + self._offset

    def add_all(self, C):

        self._offset += C

    def max(self):

        if not self._credit_to_clients:
            return ''
        clients = self._credit_to_clients.max_item()[1]
        return '' if not clients else next(iter(clients))


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
