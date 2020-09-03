// 力扣第51题，N皇后
/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


class Solution{
public:
    vector<int> queens;
    vector<vector<string>> solveNQueens(int n){
        auto solutions = vector<vector<string>> ();
        auto queens = vector<int> (n, -1);
        auto columns = unordered_set<int> ();
        auto diagonals1 = unordered_set<int> ();
        auto diagonals2 = unordered_set<int> ();
        backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }

    void backtrack(vector<vector<string>> &solutions, vector<int>& queens, int n, int row, unordered_set<int>&columns, unordered_set<int> diagonals1, unordered_set<int> &diagonals2){
        if (row == n){
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            for (int i = 0; i < n; i++) {
                if (columns.find(i) != columns.end()) {
                    continue;
                }
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }
                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }
    }
    vector<string> generateBoard(vector<int>&queens, int n){
        auto board = vector<string>();
        for (int i = 0; i < n; i++){
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};


