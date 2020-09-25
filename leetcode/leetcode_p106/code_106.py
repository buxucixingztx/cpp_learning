# 力扣第106题，从中序与后序遍历序列构造二叉树
"""
根据一棵树的中序遍历和后续遍历构造二叉树。

注意：
你可以假设树中没有重复的元素。
"""

class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildTree(self, inorder, postorder) -> TreeNode:
        if not inorder:
            return []
        
        def dfs(root, inord, postord):
            if len(postord) == 1:
                root.val = postord[0]
                return 
            media = postord.pop()
            root.val = media

            index_in = inord.index(media)
            left_in = inord[:index_in]
            right_in = inord[index_in+1:]

            left_post = postord[:len(left_in)]
            right_post = postord[len(left_in):]

            if left_in:
                root.left = TreeNode()
                dfs(root.left, left_in, left_post)
            if right_in:
                root.right = TreeNode()
                dfs(root.right, right_in, right_post)
        
        root = TreeNode()
        dfs(root, inord=inorder, postord=postorder)
        return root


class Solution:
    def buildTree(self, inorder, postorder) -> TreeNode:
        def helper(in_left, in_right):
            if in_left > in_right:
                return None
            val = postorder.pop()
            root = TreeNode(val)

            index = idx_map[val]

            root.right = helper(index+1, in_right)
            root.left = helper(in_left, index-1)

            return root
        
        idx_map = {val:idx for idx, val in enumerate(inorder)}
        return helper(0, len(inorder) - 1)


inorder = [9, 3, 15, 20, 7]
postorder = [9, 15, 7, 20, 3]

print(inorder.index(3))

