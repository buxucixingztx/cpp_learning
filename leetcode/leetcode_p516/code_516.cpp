#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void print_vector(const vector<vector<int>> &);

int main()
{
    string s = "bbbab";
    int length = s.size();
    vector<vector<int>> grid(length, vector<int>(length, 0));
    for (int i = 0; i < length; i++)
        grid[i][i] = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = i+1; j < length; j ++)
        {
            if (s[i] == s[j])
                grid[i][j] = grid[i+1][j-1] + 2;
            else
                grid[i][j] = max(grid[i][j-1], grid[i+1][j]);
        }
    }

    print_vector(grid);
    return 0;
}


void print_vector(const vector<vector<int>> & v)
{
    for (int i = 0; i < v.size(); i ++)
    {
        for (int j = 0; j < v[0].size(); j++)
            cout << v[i][j] << ' ';
        cout << endl;
    }
}
