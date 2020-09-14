// 力扣第94题，二叉树的中序遍历
/*
给定一个二叉树，返回它的中序 遍历。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;


void print(vector<int> v);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution_00{
public:
    vector<int> result;
    void dfs(TreeNode* root){
        if (root->left){
            dfs(root->left);
        }
        
        result.emplace_back(root->val);

        if (root->right){
            dfs(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root){
            return {};
        }
        dfs(root);
        return result;
    }
};


class Solution_01{
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        deque<TreeNode*> dq;
        vector<int> result;

        dq.emplace_back(root);

        while (!dq.empty()){
            TreeNode* cur = dq.front();
            dq.pop_front();
            if (!cur->left && !cur->right){
               result.emplace_back(cur->val); 
               continue;
            } 

            if (cur->right)
                dq.emplace_front(cur->right);
            dq.emplace_front(new TreeNode(cur->val));

            if (cur->left)
                dq.emplace_front(cur->left);
        }
        return result;
    }
};


/*
官方方法二：栈
*/
class Solution_02{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()){
            while (root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};


int main()
{
    TreeNode tn(1);
    // tn.right = &(TreeNode(2));
    // tn.right->left = &TreeNode(3);

    Solution_00 sl0;
    vector<int> result0 = sl0.inorderTraversal(&tn);
    cout << "result0:\n";
    print(result0);

    cin.get();
    return 0;
}



void print(vector<int> v){
    for (int num: v)
        cout << num << ' ';
    cout << endl;
}