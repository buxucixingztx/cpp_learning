// 力扣第129题，求根到叶子节点数字之和
/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。
*/
#include <iostream>
#include <deque>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{
private:
    int sum_value;
    void dfs(TreeNode* root, int value){
        if (!root->left && !root->right){
            sum_value += value * 10 + root->val;
            return;
        }
        if (root->left){
            dfs(root->left, value*10+root->val);
        }
        if (root->right){
            dfs(root->right, value*10+root->val);
        }
    }
public:
    int sumNumbers(TreeNode* root){
        if (!root){
            return 0;
        }
        dfs(root, 0);
        return sum_value;
    }
};


class Solution{
public:
    int sumNumbers(TreeNode* root){
        if (!root){
            return 0;
        }
        deque<pair<TreeNode*, int>> node_queue;
        node_queue.emplace_back(root, 0);
        TreeNode* node;
        int value;
        int sum_value = 0;
        while (!node_queue.empty()){
            pair<TreeNode*, int> nv = node_queue.front();
            node = nv.first;
            value = nv.second;
            node_queue.pop_front();
            value = value * 10 + node->val;
            if (!node->left && !node->right){
                sum_value += value;
            }
            if (node->left){
                node_queue.emplace_back(node->left, value);
            }
            if (node->right){
                node_queue.emplace_back(node->right, value);
            }
        }
        return sum_value;
    }
};


int main()
{

    return 0;
}

