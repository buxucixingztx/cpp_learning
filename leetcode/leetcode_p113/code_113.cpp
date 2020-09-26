// 力扣第113题，路径总和II
/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

// 深度优先搜索
class Solution_01{
public:
    vector<vector<int>> result;
    vector<int> path;
    int total;

    void dfs(TreeNode* root, int pathsum){
        pathsum += root->val;
        path.emplace_back(root->val);

        if (root->left){
            dfs(root->left, pathsum);
        }

        if (root->right){
            dfs(root->right, pathsum);
        }

        if (!root->left && !root->right){
            if (pathsum == total)
                result.emplace_back(path);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum){
        if (!root)
            return {};
        total = sum;
        dfs(root, 0);
        return result;
    }
};


// 广度优先搜索
class Solution_02{
public:
    vector<vector<int>>result;
    unordered_map<TreeNode*, TreeNode*> parent;
    int total;

    void getPath(TreeNode* node){
        int pathsum = 0;
        vector<int> path;
        while (node){
            pathsum += node->val;
            path.emplace_back(node->val);
            node = parent[node];
        }
        if (pathsum == total){
            reverse(path.begin(), path.end());
            result.emplace_back(path);
        } 
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum){
        total = sum;
        deque<TreeNode*> treeque;
        treeque.push_back(root);
        
        while(!treeque.empty()){
            TreeNode* node = treeque.front();
            treeque.pop_front();
            
            if (!node->left && !node->right){
               getPath(node); 
               continue;
            }
            
            if (node->left){
                treeque.push_back(node->left);
                parent[node->left] = node;
            }

            if (node->right){
                treeque.push_back(node->right);
                parent[node->right] = node;
            }
        }
        return result;
    }
};


int main()
{
    vector<int> path = {1, 2, 3, 4, 5};

    cout << "path:\n";
    for(auto i: path)
        cout << i << ' ';
    cout << endl;

    reverse(path.begin(), path.end());
    cout << "after reverse, path:\n";

    for(auto i: path)
        cout << i << ' ';
    cout << endl;

    cin.get();
    return 0;
}
