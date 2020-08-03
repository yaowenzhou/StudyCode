package main

func add(a int, b int) int {
	var sum int
	sum = a + b
	return sum
}

func main() {
	// var c int
	// c = add(100, 200)
	// for i := 0; i < 100; i++ {
	// go test_goroute(300, 300)
	// }
	// fmt.Printf("add(100, 200)=%d", c)
	for i := 0; i < 1000; i++ {
		//go fmt.Println(i)
		go test_goroute_for()
	}
	//time.Sleep(time.Minute)
}
