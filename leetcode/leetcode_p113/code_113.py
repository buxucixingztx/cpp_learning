# 力扣第113题，路径总和II
"""
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点
"""
import copy
import collections

class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None
    

""" 深度优先搜索 """
class Solution:
    def pathSum(self, root: TreeNode, sum: int):
        if not root:
            return []
        path_list = []
        path = []
        def dfs(root, path_sum):
            nonlocal path
            path.append(root.val)
            path_sum += root.val
            if root.left:
                dfs(root.left, path_sum)
            if root.right:
                dfs(root.right, path_sum)
            if not root.left and not root.right:
                if path_sum == sum:
                    path_list.append(copy.deepcopy(path))
            path.pop()
            
        dfs(root, 0)
        return path_list


""" 广度优先搜索 """
class Solution01:
    def pathSum(self, root, total):
        if not root:
            return []
        result = []
        parent = collections.defaultdict(lambda:None)
        def getPath(node):
            tmp = list()
            while node:
                tmp.append(node.val)
                node = parent[node]
            result.append(tmp[::-1])
        
        que_node = collections.deque([root])
        que_total = collections.deque([0])

        while que_node:
            node = que_node.popleft()
            rec = que_total.popleft() + node.val

            if not node.left and not node.right:
                if rec == total:
                    getPath(node)
            else:
                if node.left:
                    parent[node.left] = node
                    que_node.append(node.left)
                    que_total.append(rec)
                if node.right:
                    parent[node.right] = node
                    que_node.append(node.right)
                    que_total.append(rec)
        return result
