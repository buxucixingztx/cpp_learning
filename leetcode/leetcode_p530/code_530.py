# 力扣第530题，二叉搜索树树的最小绝对差
"""
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
"""

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    

class Solution:
    def getMinimumDifference(self, root):
        pre_order = []
        def dfs(root):
            if root.left:
                dfs(root.left)
            pre_order.append(root.val)
            if root.right:
                dfs(root.right)
        dfs(root)
        min_val = pre_order[1]-pre_order[0]
        for i,v in enumerate(pre_order[:-1]):
            if pre_order[i+1] - v < min_val:
                min_val = pre_order[i+1]-v

        return min_val