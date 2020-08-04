import React, { Component } from 'react'
import { Route } from 'react-router-dom'

import MessageDetail from './message-detail'
import MyNavLink from '../component/my-nav-link'

export default class Message extends Component {
    state = {
        messages: []
    }

    componentDidMount() {
        // 模拟发送ajax请求异步获取数据
        setTimeout(() => {
            const messages = [
                { id: 1, title: 'message001' },
                { id: 2, title: 'message002' },
                { id: 3, title: 'message003' },
                { id: 4, title: 'message004' },
                { id: 5, title: 'message005' },
            ]
            this.setState({ messages })
        }, 1000)
    }

    showDetail = (id) => {
        this.props.history.push(`/home/message/messagedetail/${id}`)
    }

    showDetail2 = (id) => {
        this.props.history.replace(`/home/message/messagedetail/${id}`)
    }

    back = () => {
        this.props.history.goBack()
    }

    forward = () => {
        this.props.history.goForward()
    }

    reqPage = () => {
        // 通过JS进行页面跳转
        window.location = 'https://www.baidu.com'
    }

    render() {
        return (
            <div>
                <ul>
                    {
                        this.state.messages.map((m, index) => (
                            <li key={index}>
                                {/*
                                    此处使用a标签会导致界面刷新，每次点击a标签都会导致页面重新发请求
                                    因为a标签不是路由标签
                                 */}
                                <MyNavLink to={`/home/message/messagedetail/${m.id}`}>{m.title}</MyNavLink>
                                {/*
                                    添加一个按钮，达到和点击路由链接同样的目的
                                    方式一：
                                        push查看的方式
                                        回退时，会回退到push之前的页面
                                    因为回调函数接受参数的时候，接受的是event
                                    并且不是我们可以控制的
                                    因此可以在回调函数中调用我们真正想要执行的函数
                                    然后传递我们想要传递的参数
                                */}
                                &nbsp;&nbsp;<button onClick={() => this.showDetail(m.id)}>push()查看</button>
                                {/*
                                    方式2：
                                        replace查看的方式
                                        替换当前页面，回退时无法回退到replace之前的页面，只能回退到replace之前的前一个页面
                                */}
                                &nbsp;&nbsp;<button onClick={() => this.showDetail2(m.id)}>replace()查看</button>
                            </li>
                        ))
                    }
                </ul>
                <p>
                    <button onClick={this.back}>回退</button>
                    <button onClick={this.forward}>前进</button>
                </p>
                <p>
                    <button onClick={this.reqPage}>页面跳转</button>
                </p>
                {/* 这种冒号写法表明冒号后面是一个参数，这个参数可以以props的形式传递给MessageDetail组件类 */}
                <Route path='/home/message/messagedetail/:id' component={MessageDetail} />
            </div>
        )
    }
}