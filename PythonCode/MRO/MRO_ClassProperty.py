class Parent(object):
    x = 1


class Son1(Parent):
    pass


class Son2(Parent):
    pass


print(Parent.x, Son1.x, Son2.x)
Son1.x = 2
print(Parent.x, Son1.x, Son2.x)
Parent.x = 3
print(Parent.x, Son1.x, Son2.x)
