package main

import (
	"fmt"
	"time"
)

func main() {
	start := time.Now().UnixNano()
	time.Sleep(time.Millisecond * 100)
	end := time.Now().UnixNano()
	fmt.Println((end - start) / 1000)
}
