import React, { Component } from 'react'
export default class App extends Component {
    state = {
        count: 0
    }

    increment = () => {
        // 1. 得到选择的增加数量
        const number = this.select.value * 1
        // 2. 得到原本的count状态
        const count = this.state.count
        // 3. 更新状态
        this.setState({ count: count + number })
    }

    decrement = () => {
        // 1. 得到选择的增加数量
        const number = this.select.value * 1
        // 2. 得到原本的count状态
        const count = this.state.count - number
        // 3. 更新状态
        this.setState({ count: count - number })
    }

    incrementIfOdd = () => {
        // 1. 得到选择的增加数量
        const number = this.select.value * 1
        // 2. 得到原本的count状态
        const count = this.state.count
        // 3. 判断一下，满足条件才更新状态
        if (count % 2 === 1) {
            // 4. 更新状态
            this.setState({ count: count + number })
        }
    }

    incrementAsync = () => {
        // 1. 得到选择的增加数量
        const number = this.select.value * 1
        // 2. 得到原本的count状态
        const count = this.state.count
        // 
        setTimeout(() => {
            // 3. 更新状态
            this.setState({ count: count + number })
        }, 1000)
    }

    render() {
        const { count } = this.state
        return (
            <div>
                <p>click {count} times</p>
                <div>
                    {/* 获取下拉框的值(自行领会) */}
                    <select ref={select => this.select = select}>
                        <option value="1">1</option>
                        <option value="2">2</option>
                        <option value="3">3</option>
                    </select>&nbsp;
                    <button onClick={this.increment}>+</button>&nbsp;
                    <button onClick={this.decrement}>-</button>&nbsp;
                    <button onClick={this.incrementIfOdd}>increment if odd</button>&nbsp;
                    <button onClick={this.incrementAsync}>increment async</button>&nbsp;
                </div>
            </div>
        )
    }
}