import gevent
import time


def f1(n):
    for i in range(n):
        print(gevent.getcurrent(), i)
        # time.sleep(0.5)
        gevent.sleep(0.5)


def f2(n):
    for i in range(n):
        print(gevent.getcurrent(), i)
        # time.sleep(0.5)
        gevent.sleep(0.5)


def f3(n):
    for i in range(n):
        print(gevent.getcurrent(), i)
        # time.sleep(0.5)
        gevent.sleep(0.5)


gevent.joinall([
    gevent.spawn(f1, 5),
    gevent.spawn(f2, 5),
    gevent.spawn(f3, 5)
])
