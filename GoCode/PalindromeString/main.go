package main

import (
	"fmt"
)

func process(rowStr string) {
	str := []rune(rowStr)
	length := len(str)
	stopNum := length / 2
	isPalindrome := true
	for i := 0; i < stopNum; i++ {
		if str[i] != str[length-i-1] {
			isPalindrome = false
		}
	}

	fmt.Println(rowStr, "\t", isPalindrome)
}

func main() {
	var str string
	fmt.Println("Please input a string:")
	fmt.Scanf("%s\n", &str)
	process(str)
}
