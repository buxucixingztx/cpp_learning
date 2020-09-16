# 力扣第226题，翻转二叉树
"""
翻转一棵二叉树
"""


class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def invertTree(self, root):
        if not root:
            return []
        
        def dfs(node):
            if not node:
                return
            node.left, node.right = node.right, node.left
            dfs(node.left)
            dfs(node.right)