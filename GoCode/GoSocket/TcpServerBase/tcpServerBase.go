package main

import (
	"fmt"
	"net"
)

func main() {
	fmt.Println("Start server...")
	listen, err := net.Listen("tcp", "0.0.0.0:50000")
	if err != nil {
		fmt.Println("Listen fail, err:", err)
		return
	}
	for {
		conn, err := listen.Accept()
		if err != nil {
			fmt.Println("Accept fail, err:", err)
			continue
		}
		go process(conn)
	}
}

func process(conn net.Conn) {
	defer conn.Close()
	for {
		buf := make([]byte, 2048)
		_, err := conn.Read(buf)
		if err != nil {
			fmt.Println("Read err:", err)
			return
		}
		fmt.Println("read: \n", string(buf))
	}
}
