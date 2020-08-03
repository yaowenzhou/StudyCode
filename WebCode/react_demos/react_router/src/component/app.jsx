import React, { Component } from 'react'
// import { NavLink, Switch, Route, Redirect } from 'react-router-dom'
import { Switch, Route, Redirect } from 'react-router-dom'
import About from '../views/about'
import Home from '../views/home'
import MyNavLink from './my-nav-link'

export default class App extends Component {
    render() {
        return (
            <div>
                <div className="row">
                    <div className="col-xs-offset-2 col-xs-8">
                        <div className="page-header"><h2>React Router Demo</h2></div>
                    </div>
                </div>

                <div className="row">
                    <div className="col-xs-2 col-xs-offset-2">
                        <div className="list-group">
                            {/*
                                NavLink可以通过设置相同的className来达到多个组件互斥的作用
                                然后结合Switch，可以达到本地切换组件显示的效果
                                activeClassName='activeClass'
                                可以使得该子项被激活时，className中带有activeClass
                                可以针对activeClass写一个样式，使得处于激活状态的子项更显眼
                                在本例中，将该样式写在了index.css文件中，并且在index.jsx中引入了
                            */}
                            {/* <NavLink className="list-group-item" to="/about" activeClassName='activeClass'>About</NavLink>
                            <NavLink className="list-group-item" to="/home" activeClassName='activeClass'>Home</NavLink> */}
                            {/* 
                                按照上面的方式直接使用NavLink
                                如果想要有自己的效果，每次都需要自行设置一遍，会有些麻烦
                                可以自己包装一下NavLink
                            */}
                            <MyNavLink className="list-group-item" to="/about">About</MyNavLink>
                            <MyNavLink className="list-group-item" to="/home">Home</MyNavLink>
                            {/* <a href="/about" className="list-group-item activeClass" aria-current='true'>About</a>
                        <a href="/home" className="list-group-item" aria-current='false'>Home</a> */}
                        </div>
                    </div>

                    <div className="col-xs-6">
                        <div className="panel">
                            <div className="panel-body">
                                <Switch>
                                    <Route path='/about' component={About} />
                                    <Route path='/home' component={Home} />
                                    <Redirect to='/about'/>
                                </Switch>
                            </div>
                        </div>
                    </div>

                </div>
            </div>
        )
    }
}