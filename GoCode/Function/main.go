package main

import (
	"fmt"
)

// import "fmt"

// //type opFunc func(int, int) int

// func add(a, b int) int {
// 	return a + b
// }

// //func operator(op opFunc, a, b int) int {
// func operator(op func(int, int) int, a, b int) int {
// 	return op(a, b)
// }

// func main() {
// 	c := add
// 	sum := operator(c, 100, 200)
// 	fmt.Println(sum)
// }
/*****************************************************************/

// func add(a int, arg ...int) int {
// 	var sum int = a
// 	for i := 0; i < len(arg); i++ {
// 		sum += arg[i]
// 	}
// 	return sum
// }

// func addString(a string, arg ...string) (result string) {
// 	result = a
// 	for i := 0; i < len(arg); i++ {
// 		result += arg[i]
// 	}
// 	return
// }

// func main() {
// 	sum := add(10)
// 	fmt.Println(sum)
// 	result := addString("Hello", " ", "Go", "!")
// 	fmt.Println(result)
// }
/****************************************************/

// func main() {
// 	var i int = 0
// 	defer fmt.Println("i = ", i)
// 	i++
// 	for j := 0; j < 3; j++ {
// 		defer fmt.Println("j = ", j)
// 	}
// }
/**************************************************/

//Anonymous function
func test(a, b int) int {
	result := func(a1, b1 int) int {
		return a1 + b1
	}(a, b)
	return result
}

func main() {
	fmt.Println(test(100, 300))
}
