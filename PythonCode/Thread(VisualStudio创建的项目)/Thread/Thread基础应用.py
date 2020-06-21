#!/usr/bin/python3

import time
import threading


def test1():
    for i in range(100):
        print("-----test1---%d---" % i)
        time.sleep(1)


def test2():
    for i in range(100):
        print("*****test2***%d***" % i)
        time.sleep(1)


def main():
    t1 = threading.Thread(target=test1)
    t2 = threading.Thread(target=test2)

    t1.start()
    t2.start()

    for i in threading.enumerate():
        print(type(i))


if __name__ == '__main__':
    main()
    time.sleep(10)
