// 力扣第538题，把二叉搜索树转换为累加树
/*
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，
使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    int value;
    void dfs(TreeNode* tn){
        if (tn == nullptr)
            return;
        if (tn->right != nullptr)
        {
            dfs(tn->right);
        }
        tn->val += value;
        value = tn->val;
        if (tn->left != nullptr)
            dfs(tn->left);
    }
    TreeNode* convertBST(TreeNode* root){
        if (root == nullptr)
            return root;
        value = 0;
        dfs(root);
        return root;
    }
};


int main()
{
    TreeNode tn(5);
    // tn->val = 5;
    // tn->val = 5;
    tn.right = new TreeNode(13);
    tn.left = new TreeNode(2);
    cout << "tn:\n";
    cout << "val = " << tn.val << "; right = " << tn.right->val << "; left = " << tn.left->val << endl;

    Solution sl;
    TreeNode *new_tn = sl.convertBST(&tn);
    cout << "new_tn:\n";
    cout << "val = " << new_tn->val << "; right = " << new_tn->right->val << "; left = " << new_tn->left->val << endl;

    cin.get();
    return 0;
}
