package main

import (
	"fmt"
	"sort"
)

func main() {
	var arr [5]int = [5]int{5, 4, 3, 2, 1}
	sort.Ints(arr[:])
	fmt.Println(arr)
}
