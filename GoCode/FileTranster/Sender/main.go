package main

import (
	"fmt"
	"io"
	"net"
	"os"
)

func sendFile(path string, conn net.Conn) {
	f, err := os.Open(path)
	if err != nil {
		fmt.Println("os.Open() error:", err)
		return
	}
	defer f.Close()

	//读文件内容，读多少发多少，一点不差
	buf := make([]byte, 1024)
	for {
		n, err1 := f.Read(buf)
		if err1 != nil {
			if err1 == io.EOF {
				fmt.Println("文件发送完毕")
			} else {
				fmt.Println("f.Read(0 errpr:", err1)
			}
			return
		}
		//发送内容
		conn.Write(buf[:n])
	}
}

func main() {
	var path = "E:\\Go\\src\\fmt\\print.go"
	info, err := os.Stat(path)
	if err != nil {
		fmt.Println("os.Stat() err:", err)
		return
	}
	fmt.Println("os.Stat() success")

	conn, err1 := net.Dial("tcp", "127.0.0.1:50000")
	if err1 != nil {
		fmt.Println("net.Dial() err:", err1)
		return
	}
	defer conn.Close()
	fmt.Println("net.Dial() success")

	//send the file name
	//var n int
	_, err2 := conn.Write([]byte(info.Name()))
	if err2 != nil {
		fmt.Println("conn.Write() err:", err2)
		return
	}
	fmt.Println("conn.Write() success")

	//receive the message OK, it indicates that the other party is ready to receive file
	buf := make([]byte, 1024)
	n, err3 := conn.Read(buf)
	if err3 != nil {
		fmt.Println("conn.Read error:", err3)
		return
	}

	if "ok" == string(buf[:n]) {
		sendFile(path, conn)
	}
}
