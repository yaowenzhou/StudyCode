import threading
import time

mutex = threading.Lock()


def mutex_test1():
    print("mutex_test1 tries to get mutex.")

    if mutex.acquire(timeout=5):
        print("mutex_test1 has gotten mutex.")
        time.sleep(10)
        mutex.release()
    else:
        print("mutex_test1 gets mutex fail.")


def mutex_test2():
    print("mutex_test2 tries to get mutex.")
    
    if mutex.acquire(timeout=5):
        print("mutex_test2 has gotten mutex.")
        time.sleep(10)
        mutex.release()
    else:
        print("mutex_test2 gets mutex fail.")


def main():
    t1 = threading.Thread(target=mutex_test1)
    t2 = threading.Thread(target=mutex_test2)
    t1.start()
    t2.start()


if __name__ == '__main__':
    main()

