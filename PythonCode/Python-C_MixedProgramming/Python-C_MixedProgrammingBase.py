# 使用如下代码即可运行C动态库(libPath)中的function函数
from ctypes import *

lib = cdll.LoadLibrary("libPath")
lib.function()
