package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 10; i++ {
		a := rand.Int()
		fmt.Println(a)
	}

	for i := 0; i < 10; i++ {
		a := rand.Intn(100) //产生100以内的随机int数
		fmt.Println(a)
	}

	for i := 0; i < 10; i++ {
		a := rand.Float32()
		fmt.Println(a)
	}
}
