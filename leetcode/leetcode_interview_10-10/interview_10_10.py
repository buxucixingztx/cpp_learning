# 力扣面试题10.10. 数字流的秩
"""
假设你正在读取一串整数。每隔一段时间，你希望能找出数字 x 的秩(小于或等于 x 的值的个数)。
请实现数据结构和算法来支持这些操作，也就是说：

实现 track(int x) 方法，每读入一个数字都会调用该方法；

实现 getRankOfNumber(int x) 方法，返回小于或等于 x 的值的个数。
"""
class TreeNode:
    def __init__(self, x, rank=0) -> None:
        self.val = x
        self.rank = rank
        self.right = None
        self.left = None

class StreamRank:
    def __init__(self) -> None:
        self.rank_tree = TreeNode(25000, 0)
    def track(self, x):
        def dfs(root, x):
            if root.val == x: 
                root.rank += 1
            elif root.val < x:
                if root.right:
                    dfs(root.right, x)
                else:
                    root.right = TreeNode(x, rank=1)
            elif root.val > x:
                root.rank += 1
                if root.left:
                    dfs(root.left, x)
                else:
                    root.left = TreeNode(x, rank=1)
        dfs(self.rank_tree, x)

    def getRankOfNumber(self, x):
        rank = 0
        def dfs(root, x):
            nonlocal rank
            if not root:
                return 
            if root.val == x:
                rank += root.rank 
            elif root.val < x:
                rank += root.rank 
                dfs(root.right, x)
            else:
                dfs(root.left, x)
        dfs(self.rank_tree, x)
        return rank