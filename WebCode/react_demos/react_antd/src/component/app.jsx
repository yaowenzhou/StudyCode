import React, {Component} from 'react'
import {Toast, Button} from 'antd-mobile'

export default class App extends Component {
    handleClick = () => {
        Toast.info('提交成功', 1)
    }

    render() {
        return (
            <div>
                <Button
                    type='primary'
                    onClick={this.handleClick}
                >提交</Button>
            </div>
        )
    }
}