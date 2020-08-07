package main

import "fmt"

func main() {
	var pipe chan int = make(chan int, 3)
	pipe <- 0
	pipe <- 1
	pipe <- 2
	for v := range pipe {
		fmt.Println(v)
	}
	<-pipe
}
