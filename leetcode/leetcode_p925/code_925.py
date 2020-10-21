# 力扣第925题，长按键入
"""
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
"""
class Solution:
    def isLongPressedName(self, name, typed):
        if not (name and typed):
            return False
        name_length = len(name)
        typed_length = len(typed)
        if typed_length < name_length:
            return False
        name_index = 1
        cur = name[0]
        last = cur
        if typed[0] != cur:
            print(False)
        for i in range(1, typed_length):
            if name_index == name_length:
                if typed[i] == cur:
                    continue
                return False

            cur = name[name_index]
            if cur == typed[i]:
                name_index += 1
                last = cur
            else:
                if typed[i] == last:
                    continue
                else:
                    return False
        if name_index == name_length:
            return True
        return False


if __name__ == "__main__":
    print('pass')
        
    
