package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Fprintln(os.Stdout, "Print to stdout...")
	file, err := os.OpenFile("./main.txt", os.O_CREATE|os.O_WRONLY, 0664)
	if err != nil {
		fmt.Fprintln(os.Stderr, "Open file ./main.txt error", err)
		return
	}
	fmt.Fprintln(file, "Print to file -- ./main.txt")
	file.Close()
}
