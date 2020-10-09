# 力扣第701题，二叉搜索树中的插入操作
"""
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 
输入数据保证，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。
"""

class TreeNode:
    def insertIntoBST(self, root, val):
        if not root:
            root = TreeNode(val)
            return root
        def dfs(ro):
            nonlocal val
            if ro.val > val:
                if ro.left:
                    dfs(ro.left)
                else:
                    ro.left = TreeNode(val)
            else:
                if ro.right:
                    dfs(ro.right, val)
                else:
                    ro.right = TreeNode(val)
        dfs(root, val)
        return root
