package main

import (
	"fmt"
	"net"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:50000")
	if err != nil {
		fmt.Println("net.Dial error:", err)
	}
	defer conn.Close()

	conn.Write([]byte("Are you ok?"))
}
