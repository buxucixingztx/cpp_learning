# 力扣第1302题，层数最深叶子节点的和
"""
给你一棵二叉树，请你返回层数最深的叶子节点的和。
"""

class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def deepestLeaveSum(self, root):
        if not root:
            return 0
        que = list()
        que.append(root)
        sum_value = 0
        while que:
            sum_value = 0
            length = len(que)
            for i in range(length):
                node = que.pop(0)
                sum_value += node.val
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
        return sum_value