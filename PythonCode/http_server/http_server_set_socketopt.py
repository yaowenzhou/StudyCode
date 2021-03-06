import socket


def service_client(client_socket):
    """为这个客户端返回数据"""
    # 1. 接收浏览器发送过来的请求，即 http 请求
    # GET / HTTP/1.1
    # ......
    client_socket.recv(1024)
    # 2. 返回http格式的数据给浏览器
    # 2.1 准备发送给浏览器的数据 ---- header
    response = "HTTP/1.1 200 OK \r\n"
    response += "\r\n"
    # 2.2 准备发送给浏览器的数据 ---- body
    response += "<h1>This is http_server_base!</h1>"
    # 3. 发送数据给客户端
    client_socket.send(response.encode("utf-8"))
    # 4. 关闭客户端
    client_socket.close()


def main():
    """用来完成整体的控制"""
    # 1. 创建套接字
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    # 2. 绑定套接字
    server_socket.bind(("", 7890))
    # 3. 设为监听套接字
    server_socket.listen(128)
    # 4. 等待新客户端的连接
    while True:
        client_socket, client_addr = server_socket.accept()
    # 5. 为这个新的客户端服务
        service_client(client_socket)
    # 6. 关闭监听套接字
    server_socket.close()


if __name__ == '__main__':
    main()
