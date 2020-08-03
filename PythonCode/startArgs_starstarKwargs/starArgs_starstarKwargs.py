def test2(a, b, *args, **kwargs):
    print("-----This is test2-----")
    print("a = ", a)
    print("b = ", b)
    print(args)
    print(kwargs)


def test1(a, b, *args, **kwargs):
    print("a = ", a)
    print("b = ", b)
    print(args)
    print(kwargs)
    test2(a, b, *args, *kwargs)


test1(10, 20, 30, 40, name="laowang", age=40)
