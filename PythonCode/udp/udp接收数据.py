import socket


def main():
    # 1. 创建套接字
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # 2. 绑定一个本地信息
    udp_socket.bind(('', 7788))
    # 3. 接收数据
    recv_data = udp_socket.recvfrom(1024)
    # recv_data 这个变量中存储得失一个元组(接收到的数据, (发送方的ip, port))
    recv_msg = recv_data[0] # 存储接收到的数据
    send_addr = recv_data[1] # 存储发送方的地址信息
    # 4. 打印接收到的数据
    # print(recv_data)
    # 发送数据时需要编码，接收数据时，需要解码
    # print("%s:%s" % (str(send_addr), recv_msg.decode("utf-8")))
    print("%s:%s" % (str(send_addr), recv_msg.decode("gbk")))
    # 5. 关闭套接字
    udp_socket.close()


if __name__ == '__main__':
    main()
