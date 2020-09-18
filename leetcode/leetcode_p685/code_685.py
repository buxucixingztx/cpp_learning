# 力扣第685题，冗余连接II
"""
在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。
每一个节点只有一个父节点，除了根节点没有父节点。

输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。
附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，
其中 u 是 v 的一个父节点。

返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
"""
import collections

"""
自己实现的方法
使用two_in来记录入度为2的节点；
使用dfs深度优先遍历来寻找环
"""
class Solution:
    def findRedundantDirectedConnection(self, edges):
        out_deg = collections.defaultdict(list)
        in_deg = collections.defaultdict(list)
        two_in = None
        loop = []
        for edge in edges:
            out_deg[edge[0]].append(edge[1])
            if in_deg[edge[1]]:
                # print('edge', edge)
                two_in = edge[1]
            else:
                in_deg[edge[1]].append(edge[0])

        def dfs(index):
            nonlocal loop
            if index in loop:
                return True
            loop.append(index)
            for out in out_deg[index]:
                if out in loop:
                    start = loop.index(out)
                    loop = loop[start:] + [out]
                    return True
                if dfs(out):
                    return True
            loop.pop()
        
        for i in range(1, len(edges)+1):
            if dfs(i):
                break

        loops = [[loop[i], loop[i+1]] for i in range(len(loop)-1)] if loop else []

        for re_edge in edges[::-1]:
            if two_in and re_edge[1] == two_in:
                if re_edge in loops:
                    return re_edge
            if not two_in and re_edge in loops:
                return re_edge
            if not loops and re_edge[1] == two_in:
                return re_edge


"""
官方题解：并查集
"""
class UnionFind:
    def __init__(self, n) -> None:
        self.ancestor = list(range(n))
    
    def union(self, index1, index2):
        self.ancestor[self.find(index1)] = self.find(index2)
    
    def find(self, index):
        if self.ancestor[index] != index:
            self.ancestor[index] = self.find(self.ancestor[index])
        return self.ancestor[index]

class Solution:
    def findRedundantDirectedConnection(self, edges):
        nodesCount = len(edges)
        uf = UnionFind(nodesCount + 1)
        parent = list(range(nodesCount + 1))
        conflict = -1
        cycle = -1
        for i, (node1, node2) in enumerate(edges):
            if parent[node2] != node2:
                conflict = i
            else:
                parent[node2] = node1
                if uf.find(node1) == uf.find(node2):
                    cycle = i
                else:
                    uf.union(node1, node2)
        
        if conflict < 0:
            return [edges[cycle][0], edges[cycle][1]]
        else:
            conflictEdge = edges[conflict]
            if cycle >= 0:
                return [parent[conflictEdge[1]], conflictEdge[1]]
            else:
                return [conflictEdge[0], conflictEdge[1]]



if __name__ == "__main__":
    # edges = [[1,2], [2,3], [3,4], [4,1], [1,5]]
    # edges = [[4,2],[1,5],[5,2],[5,3],[2,4]]
    edges = [[1,2], [1,3], [2,3]]


