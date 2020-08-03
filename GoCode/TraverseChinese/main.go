package main

import (
	"fmt"
)

func sample(_str string) {
	fmt.Printf("string print:\n")
	for _, j := range _str {
		fmt.Printf("%c", j)
	}

	fmt.Println()
	fmt.Printf("rune print:\n")
	str := []rune(_str)
	for _, j := range str {
		fmt.Printf("%c", j)
	}
	//compare Chinese character
	//str := []rune(_str)
	//str[1] == str[2]
	//also
}

func main() {
	sample("test string:看我神威，无坚不摧")
}
