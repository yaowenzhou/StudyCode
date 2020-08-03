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
                            </li>
                        ))
                    }
                </ul>
                {/* 这种冒号写法表明冒号后面是一个参数，这个参数可以以props的形式传递给MessageDetail组件类 */}
                <Route path='/home/message/messagedetail/:id' component={MessageDetail} />
            </div>
        )
    }
}