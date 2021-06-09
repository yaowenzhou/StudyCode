/*
 * @Author       : yaowenzhou
 * @Date         : 2021-06-09 23:48:58
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-06-09 23:53:32
 * @version      :
 * @Description  : 执行结果表明，当一个空接口未赋值时，其默认值为 nil
 */
package main

import "fmt"

func main() {
	type Field struct {
		Name       string
		DefaultVal interface{}
	}
	field := Field{Name: "test"}
	if field.DefaultVal == nil {
		fmt.Println("This is what i expected.")
	} else {
		fmt.Println("Oh, no, Oh no, I still need to think of another way.")
	}
}
