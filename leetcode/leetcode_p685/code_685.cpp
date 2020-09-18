// 力扣第685题，冗余连接II
/*
在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。
每一个节点只有一个父节点，除了根节点没有父节点。

输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。
附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，
其中 u 是 v 的一个父节点。

返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
*/
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> ancestor;

    UnionFind (int n){
        ancestor.resize(n);
        for (int i = 0; i < n; i++)
            ancestor[i] = i;
    };

    int find(int index){
        if (ancestor[index] != index)
            ancestor[index] = find(ancestor[index]);
        return ancestor[index];
    };

    void merge(int i1, int i2){
        ancestor[find(i1)] = find(i2);
    }
};


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges){
        int nodesCount = edges.size();
        UnionFind uf(nodesCount+1);
        vector<int> parent;
        for (int i = 0; i <= nodesCount; i++){
            parent.emplace_back(i);
        }
        int conflict = -1;
        int cycle = -1;
        for (int i = 0; i < edges.size(); i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            if (parent[node2] != node2)
                conflict = i;
            else {
                parent[node2] = node1; 
                if (uf.find(node1) == uf.find(node2))
                    cycle = i;
                else 
                    uf.merge(node1, node2);
            }    
        }
        if (conflict < 0)
            return {edges[cycle][0], edges[cycle][1]};
        else
        {
            vector<int> conflictEdge = edges[conflict];
            if (cycle >= 0)
                return {parent[conflictEdge[1]], conflictEdge[1]};
            else 
                return conflictEdge;
        }
    }
};


