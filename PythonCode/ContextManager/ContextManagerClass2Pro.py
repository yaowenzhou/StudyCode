class Sample:
    def __enter__(self):
        return self

    def __exit__(self, type_, value, traceback):
        # return isinstance(value, typeerror)
        print("Error has been handled.")
        return True

    def do_something(self):
        bar = 1/0
        return bar + 10


with Sample() as sample:
    sample.do_something()
