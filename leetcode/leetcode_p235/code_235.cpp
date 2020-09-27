// 力扣第235题，二叉搜索树的最近公共祖先
/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};


class Solution {
public:
    vector<TreeNode*> dfs(TreeNode*start, TreeNode* target){
        vector<TreeNode*> ance;
        while (start != target){
            ance.emplace_back(start);
            if (start->val > target->val)
                start = start->left;
            else
                start = start->right;
        }
        ance.emplace_back(start);
        return ance;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        vector<TreeNode*> p_list = dfs(root, p);
        vector<TreeNode*> q_list = dfs(root, q);

        for(int i = p_list.size()-1; i >= 0; i--){
            TreeNode* pa = p_list[i];
            for(auto qa: q_list){
                if (qa == pa)
                    return pa;
            }
        }
        return root;
    }
};


class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* ancestor = root;
        while (true){
            if (ancestor->val > p->val && ancestor->val > q->val){
                ancestor = ancestor->left;
            }
            else if(ancestor->val < p->val && ancestor->val < q->val){
                ancestor = ancestor->right;
            }
            else
            {
                return ancestor;
            }
        }
        return root;
    }
};


int main()
{
    vector<int> il = {1, 2, 3, 4, 5};
    cout << "3 in il " << il.at(3) << endl;

    cin.get();
    return 0;
}
