package balance

import (
	"fmt"
)

type balanceMg struct {
	allBalancer map[string]Balancer
}

var mgr = balanceMg{
	allBalancer: make(map[string]Balancer),
}

func RegisterBalancer(name string, b Balancer) {
	mgr.registerBalancer(name, b)
}

func (p *balanceMg) registerBalancer(name string, b Balancer) {
	p.allBalancer[name] = b
}

func init() {
	RegisterBalancer("random", &RandomBalance{})
	RegisterBalancer("polling", &PollingBalance{})
}

func DoBalance(name string, insts []*Instance) (inst *Instance, err error) {
	balancer, ok := mgr.allBalancer[name]
	if !ok {
		err = fmt.Errorf("Not found %s balancer", name)
		return
	}
	inst, err = balancer.DoBalance(insts)

	return
}
