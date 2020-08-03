package main

import (
	"fmt"
	"os"
)

func main() {
	var a string
	fmt.Scanln(&a)
	fmt.Println(a)

	list := os.Args
	if len(list) != 2 {
		fmt.Println("Usage: .\\main.exe file")
		return
	}
	fileName := list[1]
	info, err := os.Stat(fileName)
	if err != nil {
		fmt.Println("get fileInfo failed:", err)
		return
	}

	fmt.Println("name = ", info.Name())
	fmt.Println("size = ", info.Size())
}
