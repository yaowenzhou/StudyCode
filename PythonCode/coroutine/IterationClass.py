from collections.abc import Iterable
from collections.abc import Iterator


class Classmate(object):
    def __init__(self):
        self.names = list()
        self.current_num = 0

    def add(self, _name):
        self.names.append(_name)

    def __iter__(self):
        """
        如果想要一个对象成为一个可迭代的对象
        即可以使用for循环，那么必须实现此方法
        :return:
        """
        self.current_num = 0
        return self

    def __next__(self):
        if self.current_num < len(self.names):
            ret = self.names[self.current_num]
            self.current_num += 1
            return ret
        else:
            raise StopIteration


classmate = Classmate()

classmate.add("老王")
classmate.add("老张")
classmate.add("老李")

print("判断classmate是否时可以迭代的对象:", isinstance(classmate, Iterable))
classmate_iterator = iter(classmate)

for name in classmate:
    print(name)

for name in classmate:
    print(name)
