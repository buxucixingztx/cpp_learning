// 力扣第968题，监控二叉树
/*
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。
*/
#include <iostream>
#include <algorithm>
using namespace std;


struct Status
{
    int a, b, c;
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


class Solution {
public:
    Status dfs(TreeNode* root){
        if (root == NULL)
            return {999999, 0, 0};
        Status l = dfs(root->left);
        Status r = dfs(root->right);
        int a = l.c + r.c + 1;
        int b = min({a, l.a+r.b, l.b+r.a});
        int c = min({a, l.b+r.b});

        return {a, b, c};
    }

    int minCameraCover(TreeNode* root){
        Status result = dfs(root);
        return result.b;
    }
};


int main()
{
    int a = min({1, 3, 4});
    cout << "min value of {1, 3, 4}: " << a << endl;

    cin.get();
    return 0;
}