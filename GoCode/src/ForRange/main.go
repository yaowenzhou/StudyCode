package main

import "fmt"

func main() {
	str := "Hello, 中国"
	for i, v := range str {
		fmt.Printf("index[%d] val[%c] len[%d]\n", i, v, len([]byte(string(v))))
	}
}
