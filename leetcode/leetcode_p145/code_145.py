# 力扣第145题，二叉树的后序遍历
"""
给定一个二叉树，返回它的后序遍历。
"""

class TreeNode:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None


class Solution:
    def postorderTraversal(self, root):
        if not root:
            return []
        result = []
        def dfs(ro):
            nonlocal result
            if ro.left:
                dfs(ro.left)
            if ro.right:
                dfs(ro.right)
            result.append(ro.val)
        
        dfs(root)
        return result


class Solution_01:
    def postorderTraversal(self, root):
        if not root:
            return []
        stack = list()
        stack.append([root, 0])
        result = list()
        while len(stack) != 0:
            top = stack.pop()
            if top[1] == 0:
                stack.append([top[0], top[1]+1])
                if top[0].left:
                    stack.append([top[0].left, 0])
                continue
            if top[1] == 1:
                stack.append([top[0], top[1]+1])
                if top[0].right:
                    stack.append([top[0].right, 0])
                continue
            result.append(top[0].val)
        
        return result
