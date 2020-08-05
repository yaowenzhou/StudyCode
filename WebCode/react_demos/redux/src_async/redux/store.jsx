import { createStore, applyMiddleware } from 'redux'
import thunk from 'redux-thunk'
import { composeWithDevTools } from 'redux-devtools-extension'

import { counter } from './reducers'

// 生成一个store对象
// 第二个参数是应用中间件函数，这里表示用上异步中间件
// const store = createStore(counter, applyMiddleware(thunk)) // 内部会第一次调用reducer函数，得到初始state
// 下面的写法是为了能够使用 ReduxDevTools 调试网页
const store = createStore(
    counter,
    composeWithDevTools(applyMiddleware(thunk))
)

export default store