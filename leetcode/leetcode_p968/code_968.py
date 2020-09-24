# 力扣第968题，监控二叉树
"""
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。
"""


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


"""
官方题解：递归
本题的难度在于如何从左、右子树的状态，推导出父节点的状态。

假设当前节点为root，其左右孩子为left, right。如果要覆盖以root为根的树，有两种情况：
    若在root处安放摄像头，则孩子left, right一定也会被监控到。此时，只需要保证left的两棵子树被覆盖，同时保证right的两棵子树也被覆盖即可。
    否则，如果root处不安放摄像头，则除了覆盖root的两棵子树之外，孩子left，right之一必须要安装摄像头，从而保证root会被监控到。

根据上面的讨论，能够分析出，对于每个节点root，需要维护三种类型的状态：
    状态a：root必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目。
    状态b：覆盖整棵树需要的摄像头数目，无论root是否放置摄像头。
    状态c：覆盖两棵子树需要的摄像头数目，无论节点root本身是否被监控到。

根据定义，一定有a >= b >= c

对于节点root而言，设其左右孩子left，right对应的状态变量分别为(la, lb, lc)以及(ra, rb, rc)。
a, b的求解过程如下：
    a = lc + rc + 1
    b = min(a, min(la+rb, ra+lb))

对于c而言，要保证两棵子树被完全覆盖，要么root处放置一个摄像头，需要的摄像头数目为a；要么root处不放置摄像头，
此时两棵子树分别保证自己被覆盖，需要的摄像头数目为lb+rb。

需要注意的是，对于root而言，如果其某个孩子为空，则不能通过在该孩子处放置摄像头的方式，监控到当前节点。
因此，该孩子对应的变量a应当返回一个大整数，用于标识不可能的情形。
"""
class Solution:
    def minCameraCover(self, root):
        def dfs(r):
            if not r:
                return [999999, 0, 0]
            la, lb, lc = dfs(r.left)
            ra, rb, rc = dfs(r.right)
            a = lc + rc + 1
            b = min(a, la+rb, lb+ra)
            c = min(a, lb+rb)
            return [a, b, c]
        fa, fb, fc = dfs(root)
        return fb


if __name__ == "__main__":
    pass