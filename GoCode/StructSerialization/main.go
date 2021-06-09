/*
 * @Author       : yaowenzhou
 * @Date         : 2021-04-06 20:59:48
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-04-06 21:20:47
 * @version      :
 * @Description  :
 */
package main

import (
	"encoding/json"
	"fmt"

	"time"
)

type MyStruct struct {
	StartDate string `json:",omitempty"`
	EndDate   string `json:",omitempty"`
	Duration  int    `json:",omitempty"`
}

func main() {
	myStruct := MyStruct{}
	data, _ := json.Marshal(&myStruct)
	fmt.Println(string(data))
	var startDate time.Time
	startDateStr := startDate.Format("2006-1-2")
	fmt.Println(startDateStr)
	startDate, _ = time.Parse("2006-1-2", "2021-11-21")
	startDateStr = startDate.Format("2006-1-2")
	fmt.Println(startDateStr)
}
