
# Rehashing method to deal with
class HashTable:
    def __init__(self, capacity=1111):
        self.capacity = capacity  # should be prime number and not a multiple of the keys
        self._keys = []
        self.data = [[]] * self.capacity  # items are [key, data]

    def hashfn(self, key):
        return hash(key) % self.capacity

    def put(self, key, data):
        hash_code = self.hashfn(key)
        found = False
        for item in self.data[hash_code]:
            if item[0] == key:
                found = True
                item[1] = data
                break
        if not found:
            self.data[hash_code].append([key, data])
            self._keys.append(key)

    def get(self, key):
        hash_code = self.hashfn(key)
        found = False
        for item in self.data[hash_code]:
            if item[0] == key:
                found = True
                return item[1]
        if not found:
            raise KeyError(key)

    def remove(self, key):
        hash_code = self.hashfn(key)
        found, found_index = False, None
        for i, item in enumerate(self.data[hash_code]):
            if item[0] == key:
                found = True
                found_index = i
        if found:
            self.data[hash_code].pop(found_index)
            self._keys.remove(key)
        else:
            raise KeyError(key)

    def keys(self):
        return self._keys

    def __setitem__(self, key, value):
        self.put(key, value)

    def __getitem__(self, key):
        return self.get(key)

    def __delitem__(self, key):
        self.remove(key)


if __name__ == '__main__':
    table = HashTable()
    table['1'] = 1
    table['2'] = 2
    table['3'] = 3
    del table['3']
    for key in table.keys():
        print(table[key])
    del table['x']
