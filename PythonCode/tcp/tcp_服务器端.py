import socket


def main():
    # 1. 创建套接字
    tcp_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 2. 绑定本地信息（bind）
    tcp_server.bind(("", 54321))
    # 3. 让默认的套接字由主动变为被动（listen）
    tcp_server.listen(128)
    # 4. 等待客户端的连接（accept）
    client_socket, client_addr = tcp_server.accept()
    # 5. 接收客户端发送来的数据
    recv_data = client_socket.recv(1024)
    print(recv_data)
    # 6. 关闭套接字
    tcp_server.close()
    client_socket.close()


if __name__ == '__main__':
    main()
