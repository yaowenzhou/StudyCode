class Parent(object):
    def __init__(self):
        print("This is Parent's __init__")


class Son1(Parent):
    def __init__(self):
        print("This is Son1's __init__")
        super().__init__()


class Son2(Parent):
    def __init__(self):
        print("This is Son2's __init__")
        super().__init__()


class GrandSon(Son1, Son2):
    def __init__(self):
        print("This is GrandSon's __init__")
        super(Son2, self).__init__()


grandSon = GrandSon()
print(GrandSon.__mro__)
