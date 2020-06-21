class Fibonacci(object):
    def __init__(self, size):
        self.size = size
        self.index = 0
        self.a = 0
        self.b = 1

    def __iter__(self):
        return self

    def __next__(self):
        if self.index < self.size:
            ret = self.a
            self.a, self.b = self.b, self.a+self.b
            self.index += 1
            return ret
        else:
            raise StopIteration


fibo = Fibonacci(10)

for num in fibo:
    print(num)
