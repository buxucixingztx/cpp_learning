// 力扣第530题，二叉搜索树树的最小绝对差
/*
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    int ans = INT_MAX;
    int pre = -1;
    void dfs(TreeNode* ro){
        if (ro == nullptr){
            return;
        }
        dfs(ro->left);
        if (pre == -1){
            pre = ro->val;
        }
        else
        {
            ans = min(ans, ro->val - pre);
            pre = ro->val;
        }
        dfs(ro->right);
    }

public:
    int getMinimumDifference(TreeNode* root){
        dfs(root);
        return ans;
    }
};


int main()
{
    cout << "min(1, 3) = " << min(1, 3) << endl;
    
    cin.get();
    return 0;
}