import re

text_src = """rqwerqwerq
rqwerqwer
werqwer
rqwrq
"""
print(re.match(".*", text_src, re.S).group())
