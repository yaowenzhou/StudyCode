package main

import (
	"bufio"
	"fmt"
	"os"
)

func count(_str string) (wordCount, spaceCount, numberCount, otherCount int) {
	str := []rune(_str)
	for _, c := range str {
		switch {
		case c >= 'a' && c <= 'z':
			fallthrough
		case c >= 'A' && c <= 'Z':
			wordCount++
		case c == ' ':
			spaceCount++
		case c >= '0' && c <= '9':
			numberCount++
		default:
			otherCount++
		}
	}
	return
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	result, _, err := reader.ReadLine()
	if err != nil {
		fmt.Println("Read from console err:", err)
		return
	}
	wc, sc, nc, oc := count(string(result))
	fmt.Printf("Word count:%d\n, space count:%d\n, number count:%d\nothers count:%d\n", wc, sc, nc, oc)
}
