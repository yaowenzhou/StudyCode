package main

import (
	"fmt"
)

func test01() {
	var a [3]int
	a[0] = 100
	fmt.Println(a)
	for i := 0; i < len(a); i++ {
		fmt.Printf("%d\t", a[i])
	}
	fmt.Println()

	for index, value := range a {
		fmt.Printf("a[%d] = %d\n", index, value)
	}
}

func test03(arr [3]int) {
	arr[0] = 1000
}

func test02() {
	var a [3]int
	b := a
	b[0] = 100
	fmt.Println(a)
}

func main() {
	fmt.Println("-----test01-----")
	test01()
	fmt.Println("-----test02-----")
	test02()
	fmt.Println("-----test03-----")
	var a [3]int
	test03(a)
	fmt.Println(a)
}
