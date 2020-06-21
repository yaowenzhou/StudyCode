import threading
import time

def test1(temp):
    temp.append(33)
    print("-----in test1 temp=%s-----" % str(temp))


def test2(temp):
    print("-----in test2 temp=%s-----" %str(temp))


g_nums = [11, 22]


def main():
    # target 指定将来这个线程执行哪个函数的代码
    # args指定在线程调用函数时，给该函数传递的参数
    # args是一个元组
    # 当元组只有一个元素时，其定义语句中必须加一个“,”
    t1 = threading.Thread(target=test1, args=(g_nums,))
    t2 = threading.Thread(target=test2, args=(g_nums,))

    t1.start()
    time.sleep(1)

    t2.start()
    time.sleep(1)

    print("-----in main Thread g_nums = %s---" % str(g_nums))


if __name__ == '__main__':
    main()

