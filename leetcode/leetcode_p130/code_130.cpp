// 力扣第130题，被围绕的区域

/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution00{
public:
    int height;
    int width;
    void dfs(int h, int w, vector<vector<char>>& board){
        if (h < 0 || h >= height || w < 0 || w >= width || board[h][w] != 'O')
            return;
        board[h][w] = 'A';
        dfs(h-1, w, board);
        dfs(h+1, w, board);
        dfs(h, w-1, board);
        dfs(h, w+1, board);
    }
    void solve(vector<vector<char>>& board){
        if (board.size() == 0)
            return;
        if (board[0].size() == 0)
            return;
        height = board.size();
        width = board[0].size();
        for (int h = 0; h < height; h++){
            dfs(h, 0, board);
            dfs(h, width-1, board);
        }
        for (int w = 0; w < width; w++){
            dfs(0, w, board);
            dfs(height-1, w, board);
        }

        for (int h = 0; h < height; h++){
            for (int w = 0; w < width; w++){
                if (board[h][w] == 'A')
                    board[h][w] = 'O';
                else if (board[h][w] == 'O')
                    board[h][w] = 'X';
            }

        }
    }
};


class Solution01{
public:
    void solve(vector<vector<char>>& board){
        if (board.size() == 0)
            return;
        if (board[0].size() == 0)
            return;
        int height = board.size();
        int width = board[0].size();
        queue<pair<int, int>> dq;
        for (int h = 0; h < height; ++h){
            if (board[h][0] == 'O')
                dq.emplace(h, 0);
            if (board[h][width-1] == 'O')
                dq.emplace(h, width-1);
        }
        for (int w = 0; w < width; ++w){
            if (board[0][w] == 'O')
                dq.emplace(0, w);
            if (board[height-1][w] == 'O')
                dq.emplace(height-1, w);
        }

        while (!dq.empty()){
            pair<int, int>hw = dq.front();
            dq.pop();
            board[hw.first][hw.second] = 'A';
            vector<vector<int>> next = {{hw.first-1, hw.second}, {hw.first+1, hw.second}, {hw.first, hw.second-1}, {hw.first, hw.second+1}};
            for (auto p = next.begin(); p != next.end(); p++){
                if ((*p)[0] >= 0 && (*p)[1] >= 0 && (*p)[0] < height && (*p)[1] < width && board[(*p)[0]][(*p)[1]] == 'O')
                    dq.emplace((*p)[0], (*p)[1]);
            }
        }
        for (int h = 0; h < height; h++){
            for (int w = 0; w < width; ++w){
                if (board[h][w] == 'A')
                    board[h][w] = 'O';
                else if(board[h][w] == 'O')
                    board[h][w] = 'X';
            }
        }
    }
};

int main()
{
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    // Solution00 sl0;
    // sl0.solve(board);
    Solution01 sl1;
    sl1.solve(board);

    for (auto p = board.begin(); p != board.end(); p++){
        for (auto p1 = (*p).begin(); p1 != (*p).end(); ++p1)
            cout << *p1 << ' ';
        cout << endl;
    } 
    cin.get();
    return 0;
}