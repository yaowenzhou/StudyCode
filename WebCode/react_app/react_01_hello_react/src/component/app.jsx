import React, {Component} from 'react'
import logo from '../logo.svg'

// 默认暴露
export default class App extends Component {
    render(){
        return(
            <div>
                <img className='logo' src={logo} alt='logo' />
                <p className='title'>react app 组件</p>
            </div>
        )
    }
}