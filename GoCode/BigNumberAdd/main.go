package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func bigNumberAdd(num1, num2 string) (result string) {
	num1Index := len(num1) - 1
	num2Index := len(num2) - 1
	resultIndex := 0

	if num1Index == -1 && num2Index == -1 {
		return "0"
	}

	for _, c := range num1 {
		if c < 48 || c > '9' {
			fmt.Println("num1 is invalid")
			os.Exit(-1)
		}
	}

	for _, c := range num2 {
		if c < '0' || c > '9' {
			fmt.Println("num2 is invalid")
			os.Exit(-1)
		}
	}

	resultIndex = num1Index + 2
	if num1Index < num2Index {
		resultIndex = num2Index + 2
	}
	_result := make([]byte, resultIndex)

	var cAdd byte
	resultIndex--
	for num1Index >= 0 && num2Index >= 0 {
		cAdd = num1[num1Index] - '0' + num2[num2Index] - '0' + _result[resultIndex]
		_result[resultIndex] = '0' + cAdd%10
		_result[resultIndex-1] = cAdd / 10
		num1Index--
		num2Index--
		resultIndex--
	}
	if num1Index == -1 {
		for num2Index >= 0 {
			cAdd = num2[num2Index] - '0' + _result[resultIndex]
			_result[resultIndex] = '0' + cAdd%10
			_result[resultIndex-1] = cAdd / 10
			num2Index--
			resultIndex--
		}
	}
	if num2Index == -1 {
		for num1Index >= 0 {
			cAdd = num1[num1Index] - '0' + _result[resultIndex]
			_result[resultIndex] = '0' + cAdd%10
			_result[resultIndex-1] = cAdd / 10
			num1Index--
			resultIndex--
		}
	}
	_result[resultIndex] = _result[resultIndex] + '0'
	result = string(_result)
	fmt.Println(result)
	result = strings.TrimPrefix(result, "0")
	return
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	result, _, err := reader.ReadLine()

	if err != nil {
		fmt.Println("Read from console error:", err)
		return
	}

	strSlice := strings.Split(string(result), "+")
	if len(strSlice) != 2 {
		fmt.Println("Please input a + b")
		return
	}

	num1 := strings.TrimSpace(strSlice[0])
	num2 := strings.TrimSpace(strSlice[1])
	fmt.Println(bigNumberAdd(num1, num2))
}
