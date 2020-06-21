def create_num(size):
    a, b = 0, 1
    index = 0
    while index < size:
        # print(a)
        yield a  # 如果函数中有yield语句，那么这个就不再是函数，而是一个生成器的模板
        a, b = b, a + b
        index += 1


obj = create_num(10)
print(obj)
for num in obj:
    print(num)
