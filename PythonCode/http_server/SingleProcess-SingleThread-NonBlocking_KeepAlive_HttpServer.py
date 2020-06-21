
"""
单进程、单线程、非阻塞、长连接的Http服务器
这里的注释随时可能会被修改
从头开始写，包含了详尽的注释
首先，需要说明的是，这个是照着视频中老师的代码写的
我自己的思路并不是将监听套接字设为不阻塞
"""
import socket
import time
import re


def service_client(client_socket, request):
    request_lines = request.splitlines()
    ret = re.match(r"[^/]+(/[^ ]*)", request_lines[0])
    if ret:
        file_name = ret.group(1)
        print("file_name is: ", file_name)

    # 2. 返回http格式的数据给浏览器
    # 2.1 准备发送给浏览器的数据 ---- header
    response = "HTTP/1.1 200 OK \r\n"
    response += "\r\n"
    # 2.2 准备发送给浏览器的数据 ---- body
    f = open("./html/index.html", "rb")
    html_content = f.read()
    f.close()
    # 3. 发送数据给客户端
    # 不能直接 response += html_content，可以分两次发送
    client_socket.send(response.encode("utf-8"))
    client_socket.send(html_content)


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
            pass
        else:
            client_socket.setblocking(False)  # Set the client socket to non-blocking
            client_sockets.append(client_socket)

        for x in client_sockets:
            try:
                recv_data = x.recv(1024).decode("utf-8")
            except Exception as ret:
                pass
            else:
                if recv_data:
                    # The other party sent the data
                    service_client(client_socket, recv_data)
                else:
                    # The other party has called close()
                    client_sockets.remove(x)
                    x.close()


if __name__ == '__main__':
    main()
