# -*- coding:utf-8 -*-
# File Name:slice_operator.py
# Created Time:2018-12-31 17:50:31


class Foo(object):

    def __getitem__(self, index):
        if isinstance(index, slice):
            print("Get slice---------> start: %s, stop: %s, step: %s." \
                  % (str(index.start), str(index.stop), str(index.step)))

    def __setitem__(self, index, value):
        if isinstance(index, slice):
            print("Set slice---------> start: %s, stop: %s, step: %s." \
                  % (str(index.start), str(index.stop), str(index.step)))
            print("\tThe value is:", value)

    def __delitem__(self, index):
        if isinstance(index, slice):
            print("Delete slice------> start: %s, stop: %s, step: %s." \
                  % (str(index.start), str(index.stop), str(index.step)))


if __name__ == "__main__":
    obj = Foo()
    obj[-1:10]
    obj[-1:10:1] = [2, 3, 4, 5]
    del obj[-1:10:2]
