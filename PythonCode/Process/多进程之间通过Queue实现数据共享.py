import multiprocessing


def download_from_web(queue):
    """"
    下载数据
    模拟从网上下载的数据
    """
    data = [11, 22, 33, 44]
    for temp in data:
        # put方法存放数据
        queue.put(temp)
        queue.put_nowait(temp)
    print("---下载器已经下载完了并且存入到队列中---")


def analysis_data(queue):
    """"
    数据处理
    从队列中获取数据
    """
    waitting_analysis_data = list()
    while True:
        # get方法获取数据
        data = queue.get()
        waitting_analysis_data.append(data)
        if queue.empty():
            break
    print(waitting_analysis_data)


def main():
    # 1. 创建一个队列
    q = multiprocessing.Queue()
    # 2. 创建多个进程，将队列的引用当做实参进行传递到里面
    p1 = multiprocessing.Process(target=download_from_web, args=(q,))
    p2 = multiprocessing.Process(target=analysis_data, args=(q,))

    p1.start()
    p2.start()


if __name__ == '__main__':
    main()
