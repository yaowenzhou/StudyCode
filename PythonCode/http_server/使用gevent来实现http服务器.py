
import socket
import re
import gevent
from gevent import monkey

monkey.patch_all()


def service_client(client_socket):
    """为这个客户端返回数据"""
    # 1. 接收浏览器发送过来的请求，即 http 请求
    # GET / HTTP/1.1
    # ......
    request = client_socket.recv(1024).decode("utf-8")
    request_lines = request.splitlines()
    print(request_lines)
    ret = re.match(r"[^/]+(/[^ ]*)", request_lines[0])
    if ret:
        file_name = ret.group(1)
        if file_name == "/":
            file_name = "/index.html"

    # 2. 返回http格式的数据给浏览器
    # 2.1 准备发送给浏览器的数据 ---- header
    response = "HTTP/1.1 200 OK \r\n"
    response += "\r\n"
    # 2.2 准备发送给浏览器的数据 ---- body
    try:
        f = open("./html" + file_name, "rb")

    except:
        # 如果找不到资源，就只发送response
        response = "HTTP/1.1 404 NOT FOUND\r\n"
        client_socket.send(response.encode("utf-8"))

    else:
        # 如果找到了资源，则需要发送response，然后再发送html_content
        html_content = f.read()
        f.close()
        # 3. 发送数据给客户端
        # 不能直接 response += html_content，可以分两次发送
        client_socket.send(response.encode("utf-8"))
        client_socket.send(html_content)

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
        # 创建新的进程用于和新的客户端通信
        gevent.spawn(service_client, client_socket)

    # 6. 关闭监听套接字
    server_socket.close()


if __name__ == '__main__':
    main()
