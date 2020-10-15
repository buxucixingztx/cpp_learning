# 力扣第116题--填充每个节点的下一个右侧节点指针
"""
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度.
"""

class Node:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root):
        if not root:
            return root
        que = list()
        que.append(root)
        while que:
            length = len(que)
            for i in range(length):
                start = que.pop(0)
                
                if i < length - 1:
                    start.next = que[0]
                
                if start.left:
                    que.append(start.left)
                if start.right:
                    que.append(start.right)
        return root


class Solution_01:
    def connect(self, root):
        if not root:
            return root
        new_root = root
        while new_root.left:
            start = new_root
            while start:
                start.left.next = start.right
                if start.next:
                    start.right.next = start.next.left
                start = start.next

            new_root = new_root.left
        return root
