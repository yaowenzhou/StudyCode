package test

import (
	"testing"
)

func TestAdd(t *testing.T) { //TestAdd必须大写的Test开头
	result := add(2, 8) //测试add函数
	if result != 10 {
		t.Fatalf("add is not right") //致命错误记录
		return
	}

	t.Logf("add is right") //记录一些常规信息
}

func TestSub(t *testing.T) {
	result := sub(2, 8)
	if result != -6 {
		t.Fatalf("add is not right")
		return
	}

	t.Logf("add is right")
}
