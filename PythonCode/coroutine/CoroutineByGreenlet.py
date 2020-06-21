from greenlet import greenlet
import time


def task1():
    while True:
        print("----A----")
        # 切换到gr2中运行
        gr2.switch()
        time.sleep(0.5)


def task2():
    while True:
        print("----B----")
        # 切换到gr1中运行
        gr1.switch()
        time.sleep(0.5)


gr1 = greenlet(task1)
gr2 = greenlet(task2)

# 切换到gr1中运行
gr1.switch()
