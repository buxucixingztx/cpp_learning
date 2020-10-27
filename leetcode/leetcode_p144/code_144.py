# 力扣第144题，二叉树的前序遍历
"""
给定一个二叉树，返回它的前序遍历
"""
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root):
        result = []
        if not root:
            return []

        def dfs(ro):
            nonlocal result
            result.append(ro.val)
            if ro.left:
                dfs(ro.left)
            if ro.right:
                dfs(ro.right)
        dfs(root)
        return result



class Solution_01:
    def preorderTraversal(self, root):
        if not root:
            return []
        stack = collections.deque()
        stack.append(root)
        result = []
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return result

