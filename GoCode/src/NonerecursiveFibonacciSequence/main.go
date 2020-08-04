package main

import (
	"fmt"
)

func fabonacci(size int) {
	if size < 2 {
		fmt.Println("size must be greater than 2")
	}
	a := make([]uint64, size)

	a[0] = 1
	a[1] = 1

	for i := 2; i < size; i++ {
		a[i] = a[i-1] + a[i-2]
	}
	for _, v := range a {
		fmt.Println(v)
	}
}

func main() {
	fabonacci(22)
}
