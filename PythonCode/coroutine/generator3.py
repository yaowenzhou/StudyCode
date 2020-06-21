def create_num(size):
    a, b = 0, 1
    index = 0
    while index < size:
        # print(a)
        yield a  # 如果函数中有yield语句，那么这个就不再是函数，而是一个生成器的模板
        a, b = b, a + b
        index += 1
    return "end..."


obj = create_num(10)
while True:
    try:
        """
        但凡是迭代器，就可以用next函数操作它
        生成器对象虽然是一种特殊的迭代器，并没有__next__方法
        但是依旧可以被next函数操作
        """
        ret = next(obj)
        print(ret)
    except Exception as result:
        """
        如果想获得迭代器模板的返回值
        必须在捕获到的异常中，使用 ex.value 才能得到
        (
        
        这是一个异常对象的成员变量，不是方法或者函数)
        """
        print(result.value)
        break
