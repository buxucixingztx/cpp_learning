# 力扣第129题，求根到叶子节点数字之和
"""
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。
"""
import collections

class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def sumNumbers(self, root):
        if not root:
            return 0
        sum_value = 0
        def dfs(ro, fv):
            nonlocal sum_value
            if not ro.left and not ro.right:
                sum_value += fv * 10 + ro.val
            if ro.left:
                dfs(ro.left, fv*10+ro.val)
            if ro.right:
                dfs(ro.right, fv*10+ro.val)
        dfs(root, 0)
        return sum_value


class Solution_01:
    def sumNumbers(self, root):
        if not root:
            return 0
        node_queue = collections.deque()
        node_queue.append([root, 0])
        sum_value = 0
        while node_queue:
            node, value = node_queue.popleft()
            if not node.left and not node.right:
                sum_value += value * 10 + node.val
            if node.left:
                node_queue.append([node.left, value*10+node.val])
            if node.right:
                node_queue.append([node.right, value*10+node.val])
        return sum_value

if __name__ == "__main__":
    pass