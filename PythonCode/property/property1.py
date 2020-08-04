class Foo:
    def get_bar(self):
        print("getter...")
        return 'laowang'

    def set_bar(self, value):
        """必须两个参数"""
        print("setter...")
        return 'set value' + value

    def del_bar(self):
        print("deleter...")
        return 'laowang'

    BAR = property(get_bar, set_bar, del_bar, "Description ...")


obj = Foo()
result = obj.BAR  # 自动调用get_bar方法，并且获取方法的返回值
obj.BAR = 'alex'
print(result)
print(Foo.BAR.__doc__)  # 查看__doc__必须使用类对象调用
