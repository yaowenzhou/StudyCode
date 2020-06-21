import socket


def main():
    # 1. 创建套接字
    server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 2. 绑定本地信息
    server_sock.bind(("", 54321))
    # 3. 开始监听
    server_sock.listen(128)  # 参数表示处于连接请求状态的最大请求数量
    # 开始循环，为多个套接字服务
    while True:
        print("等待一个新的客户端连接")
        # 4. 等待新的连接请求，此函数会返回一个元组：客户端套接字，客户端地址
        client_sock, client_addr = server_sock.accept()
        # 内存循环，为客户端服务
        while True:
            # 5. 接收客户端的数据，此函数会阻塞，直到“接收到客户端发送的数据”或者“客户端套接字关闭”
            recv_data = client_sock.recv(1024)
            # 如果recv解阻塞，那么有两种方式：
            # 1. 客户端发送过来数据
            # 2. 客户端调用 close，此时recv_data为空
            print(type(client_addr[0]))

            if recv_data:
                # 服务：将数据回送给客户端
                print("接收到客户端 %s 发送过来的数据，内容是：\n\t%s" % (str(client_addr), recv_data.decode("utf-8")))
                client_sock.send("I have get your message!".encode("utf-8"))
            else:
                print("%s 已断开" % str(client_addr))
                break
        # 关闭客户端套接字
        client_sock.close()
    # 关闭服务端套接字
    server_sock.close()


if __name__ == '__main__':
    main()
