import { INCREMENT, DECREMENT } from './action-types'
// 同步的action都是返回一个对象
// 异步的action都是返回一个函数

// 增加
export const increment = (number) => ({
    type: INCREMENT,
    data: number
})

// 减少
export const decrement = (number) => ({
    type: DECREMENT,
    data: number
})

// 异步action
export const incrementAsync = (number) =>  {
    // 这里的dispatch竟然不需要引入直接就可以用？？？
    return (dispatch) => {
        // 异步的代码
        setTimeout(() => {
            // 1s 之后才去分发一个增加的action
            dispatch(increment(number))
        }, 1000)
    }
}