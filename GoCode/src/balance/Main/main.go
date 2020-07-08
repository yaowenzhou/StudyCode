package main

import (
	"balance"
	"fmt"
	"math/rand"
	"time"
)

// func init() {
// 	fmt.Println("This is main.go init1...")
// }

// func init() {
// 	fmt.Println("This is main.go init2...")
// }

func main() {
	insts := make([]*balance.Instance, 10)
	for i := 0; i < 10; i++ {
		host := fmt.Sprintf("192.168.%d.%d", rand.Intn(255), rand.Intn(255))
		port := rand.Intn(65536)
		insts[i] = balance.NewInstance(host, port)
	}

	//balancer := &balance.RandomBalance{}
	for {
		inst, err := balance.DoBalance("hash", insts)
		if err != nil {
			fmt.Println("do balancer err:", err)
			return
		}
		fmt.Println(inst)
		time.Sleep(2 * time.Second)
	}

}
