#!/usr/bin/python3

import threading
import time

class MyThread(threading.Thread):
    def run(self):
        for i in range(10):
            time.sleep(1)
            msg = "I'm " + self.name + " @ " + str(i)  # name 属性中保存的时当前线程的名字
            print(msg)


if __name__ == '__main__':
    t = MyThread()
    t.start()
