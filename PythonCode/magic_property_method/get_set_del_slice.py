class Foo1(object):
    def __getslice__(self, i, j):
        print("__getslice", i, j)

    def __setslice__(self, i, j, sequence):
        print("__setslice__", i, j, sequence)

    def __delslice__(self, i, j):
        print("__delslice__", i, j)


obj = Foo1()
obj[-1:1]
obj[0:1] = [11, 22, 33, 44]
del obj[0:2]
