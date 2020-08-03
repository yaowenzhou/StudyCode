package balance

import (
	"errors"
)

type PollingBalance struct {
	curIndex int
}

func (p *PollingBalance) DoBalance(insts []*Instance, key ...string) (inst *Instance, err error) {
	if len(insts) == 0 {
		err = errors.New("No instance")
		return
	}

	length := len(insts)
	if p.curIndex >= length {
		p.curIndex = 0
	}
	inst = insts[p.curIndex]
	p.curIndex++
	return
}
