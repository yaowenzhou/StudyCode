// import React from 'react'
import {connect} from 'react-redux'
import {increment, decrement, incrementAsync} from '../redux/actions'
import Counter from '../component/counter'

/* 
    state 是在store中保存的，并且会在connect时，由Provider标签传递给箭头函数
    index.jsx中传递给Provider标签的store初始化时定义的createStore函数中定义并且初始化了state
    connect会将参数列表中的参数打包然后传递给以“...”的形式传递给App
*/
export default connect(
    state => ({ count: state }),
    { increment, decrement, incrementAsync }
)(Counter)