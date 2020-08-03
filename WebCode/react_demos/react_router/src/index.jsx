import React from 'react'
// import ReactDOM from 'react-dom'
import { render } from 'react-dom'
import { BrowserRouter } from 'react-router-dom'
import App from './component/app'
import './index.css'

// 添加了路由组件之后，不能这么写了，要管理整个组件要使用<BrowserRouter>
// render(<App />, document.getElementById('root'))
render(
    (
        <BrowserRouter>
            <App />
        </BrowserRouter>
    ),
    document.getElementById('root')
)