def create_num(size):
    a, b = 0, 1
    index = 0
    while index < size:
        ret = yield a
        print(">>>>ret>>>>", ret)
        a, b = b, a+b
        index += 1


obj = create_num(10)

num = next(obj)
print(num)

num = obj.send("hahahaha")
print(num)
"""
解释：
send的方式和next的方式效果差不多，但是send方法可以传递参数
以此生成器为例，第一次执行next的方式后，a = 0
生成器的代码会在yield执行完之后，停下来(即只执行完等号右边的代码就停下来)
等到再执行send方法的时候
ret = xxx开始生效，但是yield是没有返回值的，无法完成这个等号语句
此处语句会将send方法传递进去的参数作为yield的执行结果，赋值给ret
如果第一次启动生成器时，用send方法启动，则应该传递None作为参数
eg:
obj.send(None)
"""
