# 力扣第538题，把二叉搜索树转换为累加树
"""
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，
使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
"""

class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None
    
"""
题目要求把二叉搜索树转换成累加树，我们就把反向遍历二叉树，把累加的和不断向上传递并累加
"""
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        def dfs(r, value):
            if isinstance(r.right, TreeNode):
                right = dfs(r.right, value)
            elif r.right:
                right = r.right + value
            else:
                right = value
            r.val = right + r.val
            if isinstance(r.left, TreeNode):
                left = dfs(r.left, r.val)
            elif r.left:
                r.left = r.left + r.val
                left = r.left
            else:
                return r.val
            
            return left
        
        dfs(root, 0)
        return root


if __name__ == "__main__":
    tn = TreeNode(5)
    tn.left = 2
    tn.right = 13

    print('tn--------------')
    print(tn.right)
    print(tn.val)
    print(tn.left)

    sl = Solution()
    new_tn = sl.convertBST(tn)

    print('new_tn-------------')
    print(new_tn.right)
    print(new_tn.val)
    print(new_tn.left)


