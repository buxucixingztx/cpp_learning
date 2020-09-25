# 力扣第501题，二叉搜索树中的众数
"""
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
"""

class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def findMode(self, root):
        record = {}
        mode = []
        max_value = 0
        def dfs(r):
            nonlocal max_value, mode
            if not r:
                return 
            record[r.val] = record.get(r.val, 0) + 1
            if record[r.val] > max_value:
                max_value = record[r.val]
                mode = [r.val]
            elif record[r.val] == max_value:
                mode.append(r.val)
            dfs(r.left)
            dfs(r.right)
        dfs(root)
        return mode
        

