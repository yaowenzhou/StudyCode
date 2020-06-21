# import socket
# import re
#
#
# def service_client(client_socket):
#     """为这个客户端返回数据"""
#     # 1. 接收浏览器发送过来的请求，即 http 请求
#     # GET / HTTP/1.1
#     # ......
#     request = client_socket.recv(1024).decode("utf-8")
#     request_lines = request.splitlines()
#     ret = re.match(r"[^/]+(/[^ ]*)", request_lines[0])
#     if ret:
#         file_name = ret.group(1)
#         print("file_name is: ", file_name)
#
#     # 2. 返回http格式的数据给浏览器
#     # 2.1 准备发送给浏览器的数据 ---- header
#     response = "HTTP/1.1 200 OK \r\n"
#     response += "\r\n"
#     # 2.2 准备发送给浏览器的数据 ---- body
#     f = open("./html/index.html", "rb")
#     html_content = f.read()
#     f.close()
#     # 3. 发送数据给客户端
#     # 不能直接 response += html_content，可以分两次发送
#     client_socket.send(response.encode("utf-8"))
#     client_socket.send(html_content)
#     # 4. 关闭客户端
#     client_socket.close()
#
#
# def main():
#     """用来完成整体的控制"""
#     # 1. 创建套接字
#     server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#     # 2. 绑定套接字
#     server_socket.bind(("", 7890))
#     # 3. 设为监听套接字
#     server_socket.listen(128)
#     # 4. 等待新客户端的连接
#     while True:
#         client_socket, client_addr = server_socket.accept()
#     # 5. 为这个新的客户端服务
#         service_client(client_socket)
#     # 6. 关闭监听套接字
#     server_socket.close()
#
#
# if __name__ == '__main__':
#     main()

"""
这里的注释随时可能会被修改
从头开始写，包含了详尽的注释
首先，需要说明的是，这个是照着视频中老师的代码写的
我自己的思路并不是将监听套接字设为不阻塞
"""
import socket
import time


def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setblocking(False)  # 设置监听socket对象不阻塞
    # 设置端口在没有关闭的情况下，可重复绑定，虽然我也不明白为啥不是socket.SO_REUSEPORT
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind(("", 8090))
    server_socket.listen(128)
    """
    Start the accept loop
    Exception handling is required here
    Because it's actually tested in the case of "setblocking(False)"
    If there is no connection request when the accept function is executed,
        the accept function throws an error immediately instead of returning an empty object
    """
    # define a list of client_socket
    client_sockets = list()

    while True:
        time.sleep(1)
        try:
            client_socket, client_addr = server_socket.accept()
        except Exception as ret:
            print("-----No new client connection requests---")
        else:
            print("---No exception is generated, indicating that a new client is coming---")
            client_socket.setblocking(False)  # Set the client socket to non-blocking
            client_sockets.append(client_socket)

        for x in client_sockets:
            try:
                recv_data = client_socket.recv(1024)
            except Exception as ret:
                print("---This client didn't send data.---")
            else:
                if recv_data:
                    # The other party sent the data
                    print("---This client has send data.---")
                else:
                    # The other party has called close()
                    client_sockets.remove(client_socket)
                    client_socket.close()


if __name__ == '__main__':
    main()
