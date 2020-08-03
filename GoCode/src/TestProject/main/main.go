package main

import (
	"fmt"
	"time"
)

func main() {
	ticker := time.NewTicker(time.Second)
	stop := make(chan bool, 1)

	go func(ticker *time.Ticker, stop chan bool) {
		defer fmt.Println("goroutine exit...")
		for {
			select {
			case t := <-ticker.C:
				fmt.Println(t)
			case <-stop:
				break
			}
		}
	}(ticker, stop)

	fmt.Println("Start sleep 5s...")
	time.Sleep(2 * time.Second)
	ticker.Stop()
	stop <- true
	time.Sleep(3 * time.Second)
	fmt.Println("Sleep 5s end...")
}
