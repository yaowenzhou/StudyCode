package main

import (
	"fmt"
	"net"
)

func main() {
	listener, err0 := net.Listen("tcp", "0.0.0.0:50000")
	if err0 != nil {
		fmt.Println("Listen error,", err0)
		return
	}
	defer listener.Close()

	conn, err1 := listener.Accept()
	if err1 != nil {
		fmt.Println("Accept erroor:", err1)
		return
	}
	defer conn.Close()

	buf := make([]byte, 2048)
	n, err2 := conn.Read(buf)
	if err2 != nil {
		fmt.Println("conn Read error:", err2)
		return
	}
	fmt.Println(string(buf[:n]))
}
