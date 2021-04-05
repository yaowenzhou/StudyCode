#!/bin/bash
###
# @Author       : yaowenzhou
# @Date         : 2021-04-05 16:08:13
# @LastEditors  : yaowenzhou
# @LastEditTime : 2021-04-05 16:11:15
# @version      :
# @Description  : shell 加法
###

func() {
    m=1
    n=2
    echo $((m + n))
}

ret=$(func)

echo $ret
