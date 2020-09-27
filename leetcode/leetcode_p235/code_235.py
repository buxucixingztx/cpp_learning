# 力扣第235题，二叉搜索树的最近公共祖先
"""
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。
"""
import collections

class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        ancestor_dict = collections.defaultdict(lambda: None)
        def dfs(ro):
            if not ro:
                return 
            if ro == p or ro == q:
                return
            if ro.left:
                ancestor_dict[ro.left] = ro
                dfs(ro.left)
            if ro.right:
                ancestor_dict[ro.right] = ro
                dfs(ro.right)
        
        dfs(root)
        
        p_list = []
        node = p
        while node != root:
            p_list.append(node)
            node = ancestor_dict[node]
        node = q
        while node != root:
            if node in p_list:
                return node
            node = ancestor_dict[node]
        return root


class Solution_01:
    def lowestCommonAncestor(self, root, p, q):
        def dfs(start, target, ances_list):
            ances_list.append(start)
            if start == target:
                return ances_list
            if start.val < target.val:
                dfs(start.right, target, ances_list)
            else:
                dfs(start.left, target, ances_list)
        
        p_list = dfs(root, p, [])
        q_list = dfs(root, q, [])
        for qa in q_list[::-1]:
            if qa in p_list:
                return qa
        return root


class Solution_02:
    def lowestCommonAncestor(self, root, p, q):
        while True:
            if p.val < root.val and q.val < root.val:
                root = root.left
            elif p.val > root.val and q.val > root.val:
                root = root.right
            else:
                return root
