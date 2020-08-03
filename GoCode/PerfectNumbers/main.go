package main

import (
	"fmt"
)

func isPerfectNumbers(n int) bool {
	sum := 0
	half := n / 2
	for i := 1; i <= half; i++ {
		if n%i == 0 {
			sum += i
		}
	}
	return sum == n
}

func printPerfectNumbers(n int) {
	for i := 1; i <= n; i++ {
		if isPerfectNumbers(i) {
			fmt.Println(i)
		}
	}
}

func main() {
	printPerfectNumbers(1000)
}
