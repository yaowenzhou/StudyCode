package main

import (
	"fmt"
	"io"
	"net"
	"os"
)

func RecvFile(fileName string, conn net.Conn) {
	f, err := os.OpenFile(fileName, os.O_WRONLY|os.O_CREATE, 0644)
	if err != nil {
		fmt.Println("os.OpenFile() error:", err)
		return
	}
	defer f.Close()

	buf := make([]byte, 1024)
	for {
		n, err1 := conn.Read(buf)
		if err != nil {
			if err1 == io.EOF {
				fmt.Println("文件接收完毕")
			} else {
				fmt.Println("conn.Read() error:", err1)
			}
			return
		}
		if n == 0 {
			fmt.Println("文件接收完毕")
			return
		}
		f.Write(buf[:n])
	}
}

func main() {
	listener, err := net.Listen("tcp", "127.0.0.1:50000")
	if err != nil {
		fmt.Println("net.Listen() error:", err)
		return
	}
	defer listener.Close()

	conn, err1 := listener.Accept()
	if err1 != nil {
		fmt.Println("listener.Accept() error:", err1)
		return
	}
	defer conn.Close()

	buf := make([]byte, 1024)
	n, err2 := conn.Read(buf)
	if err2 != nil {
		fmt.Println("conn.Read() error:", err2)
		return
	}
	conn.Write([]byte("ok"))

	fileName := string(buf[:n])
	RecvFile(fileName, conn)
}
