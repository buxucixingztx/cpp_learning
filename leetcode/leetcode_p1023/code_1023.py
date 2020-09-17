# 力扣第1023题，驼峰式匹配
"""
如果我们可以将小写字母插入模式串 pattern 得到待查询项 query，那么待查询项与给定模式串匹配。
（我们可以在任何位置插入每个字符，也可以插入 0 个字符。）

给定待查询列表 queries，和模式串 pattern，返回由布尔值组成的答案列表 answer。
只有在待查项 queries[i] 与模式串 pattern 匹配时， answer[i] 才为 true，否则为 false。
"""

# queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
# pattern = "FB"
queries = ["IXfGawluvnCa","IsXfGaxwulCa","IXfGawlqtCva","IXjfGawlmeCa","IXfGnaynwlCa","IXfGcamwelCa"]
pattern = "IXfGawlCa"

result = []
for query in queries:
    ip = 0
    iq = 0
    
    while iq < len(query):
        if query[iq].isupper() and query[iq] != pattern[ip]:
            break
        if query[iq] == pattern[ip]:
            flag = False
            ip += 1
            iq += 1
            while ip < len(pattern):
                if pattern[ip] == query[iq]:
                    ip += 1
                    iq += 1
                    continue
                if pattern[ip].isupper():
                    break
                if pattern[ip] != query[iq] and query[iq].islower():
                    iq += 1
                elif pattern[ip] != query[iq] and query[iq].isupper():
                    flag = True
                    break
            if flag:
                break
        if ip == len(pattern):
            for i in range(iq, len(query)):
                if query[i].isupper():
                    result.append(False)
                    break
            else:
                result.append(True)
            break
        iq += 1
    
    if ip != len(pattern):
        result.append(False)

print(result)