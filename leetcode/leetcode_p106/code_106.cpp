// 力扣第106题，从中序与后序遍历序列构造二叉树
/*
根据一棵树的中序遍历和后续遍历构造二叉树。

注意：
你可以假设树中没有重复的元素。
*/

#include <iostream>
#include <vector>
#include <stack>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        if (postorder.size() == 0){
            return nullptr;
        }

        auto root = new TreeNode(postorder[postorder.size()-1]);
        auto s = stack<TreeNode*>();
        s.push(root);
        int inorderIndex = inorder.size() - 1;
        for (int i = int(postorder.size()) - 2; i >= 0; i--){
            int postorderVal = postorder[i];
            auto node = s.top();
            if (node->val != inorder[inorderIndex]) 
            {
                node->right = new TreeNode(postorderVal);
                s.push(node->right);
            }
            else
            {
                while(!s.empty() && s.top()->val == inorder[inorderIndex]){
                    node = s.top();
                    s.pop();
                    inorderIndex--;
                }
                node->left = new TreeNode(postorderVal);
                s.push(node->left);
            }
        }
        return root;
    }
};



