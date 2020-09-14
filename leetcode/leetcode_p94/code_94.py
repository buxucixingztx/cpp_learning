# 力扣第94题，二叉树的中序遍历
"""
给定一个二叉树，返回它的中序 遍历。
"""
from collections import deque

class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None

class Solution_00:
    def inorderTraversal(self, root):
        result = []

        def dfs(root):
            if not root:
                return []
            if isinstance(root.left, TreeNode):
                dfs(root.left)
            elif root.left:
                result.append(root.left)

            result.append(root.val)

            if isinstance(root.right, TreeNode):
                dfs(root.right)
            elif root.right:
                result.append(root.right)
        
        dfs(root)

        return result


class Solution_01:
    def inorderTraversal(self, root):
        if not root:
            return []
        result = []
        dq = deque()
        dq.append(root)

        while dq:
            cur = dq.popleft()
            if not isinstance(cur, TreeNode):
                result.append(cur)
                continue
            if cur.right:
                dq.appendleft(cur.right)
            
            dq.appendleft(cur.val)

            if isinstance(cur.left, TreeNode):
                dq.appendleft(cur.left)
            elif cur.left:
                result.append(cur.left)

        return result


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = 3
    root.left.right = TreeNode(4)
    root.left.right.left = 5
    root.right = TreeNode(6)
    root.right.left = 7
    root.right.right = 8

    sl0 = Solution_00()
    result0 = sl0.inorderTraversal(root)
    print(result0)

    sl1 = Solution_01()
    result1 = sl1.inorderTraversal(root)
    print('result1:', result1)
