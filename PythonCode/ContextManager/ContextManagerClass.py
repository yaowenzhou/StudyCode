# -*- coding: utf-8 -*-
# 自定义 Context Manager


class File(object):
    def __init__(self, filename, mode):
        # 设定文本名与打开方式
        self.filename = filename
        self.mode = mode

    # 资源配置
    def __enter__(self):
        print("打开文本：" + self.filename)
        self.open_file = open(self.filename, self.mode)
        return self.open_file

    # 资源回收（关闭文本）
    def __exit__(self, type, value, trace):
        print("关闭文本：" + self.filename)
        self.open_file.close()


with File("filename", 'w') as f:
    print("写入文本...")
    f.write("Hello, world!")
