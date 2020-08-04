class Goods(object):
    def __init__(self, price):
        self._price = price

    @property
    def price(self):
        return self._price

    @price.setter
    def price(self, value):
        self._price = value

    # del xxx.price 将会自动调用此方法
    @price.deleter
    def price(self):
        print("@price.deleter")


a = Goods(100)
a.price = 1000
del a.price
print(a.price)
