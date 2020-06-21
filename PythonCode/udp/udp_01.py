#!/usr/bin/python3
import socket

def main():
    # 创建一个 udp 套接字
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    '''
    可以使用套接字收发数据
    udp_socket("data", 对方的ip以及port（元组）)
    '''
    udp_socket.sendto(b"Hello Socket", ("127.0.0.1", 8080))

    # 关闭套接字
    udp_socket.close()


if __name__ == '__main__':
    main()
