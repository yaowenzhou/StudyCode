class Foo(object):
    def __getitem__(self, item):
        print("__getitem", item)

    def __setitem__(self, key, value):
        print("__setitem__", key, value)

    def __delitem__(self, key):
        print("__delitem__", key)


obj = Foo()
result = obj['k1']
obj['k2'] = 'laowang'
del obj['k1']
