class ArrayList:
    def __init__(self):
        self.n = 0
        self.capacity = 1
        self.__array = [None] * self.capacity

    def __len__(self):
        return self.n

    def __getitem__(self, item):
        if 0 <= item < self.n:
            return self.__array[item]
        return IndexError("index error")

    def __repr__(self):
        return ", ".join([str(element) for element in self.__array[:self.n]])

    def append(self, element):
        if self.n == self.capacity:
            self._resize(2*self.capacity)
        self.__array[self.n] = element
        self.n += 1

    def _resize(self, new_capacity):
        new_array = [None] * new_capacity
        for i in range(self.n):
            new_array[i] = self.__array[i]
        self.__array= new_array
        self.capacity = new_capacity


if __name__ == '__main__':
    l = ArrayList()
    l.append(1)
    print(l)
    l.append(2)
    print(l)
    for i in range(10):
        l.append(i)
    print(l)