package main

import (
	"balance"
	"fmt"
	"hash/crc32"
	"math/rand"
	"time"
)

type HashBalance struct {
}

func init() {
	balance.RegisterBalancer("hash", &HashBalance{})
}

func (p *HashBalance) DoBalance(insts []*balance.Instance, key ...string) (inst *balance.Instance, err error) {
	rand.Seed(time.Now().Unix())
	var defKey string = fmt.Sprintf("%d", rand.Int())

	if len(key) > 0 {
		defKey = key[0]
	}

	length := len(insts)
	if length == 0 {
		err = fmt.Errorf("No backend instance")
	}

	// hashVal := crc64.Checksum([]byte(defKey), crc64.MakeTable(crc64.ECMA))
	// index := int(hashVal) % length
	hashVal := crc32.Checksum([]byte(defKey), crc32.MakeTable(crc32.IEEE))
	index := int(hashVal) % length
	//index := rand.Int() % length
	inst = insts[index]
	return
}
