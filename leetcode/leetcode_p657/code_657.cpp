// 力扣第657题，机器人能否返回原点
/*
在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。

移动顺序由字符串表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。

注意：机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。
*/
#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution_00{
public:
    bool judgeCircle(string moves){
        for (auto p = moves.begin(); p != moves.end(); ++p){
            if (*p == 'U')
                point[1]++;
            else if(*p == 'D')
                point[1]--;
            else if(*p == 'R')
                point[0]++;
            else if(*p == 'L')
                point[0]--;
        }
        bool result = false;
        if (point[0] == 0 && point[1] == 0)
            result = true;
        return result;
    }
private:
    vector <int> point = {0, 0};
};


int main()
{
    string moves = "UUDD";
    Solution_00 sl0;
    bool result_0 = sl0.judgeCircle(moves);
    cout << "move step: " << moves << endl;
    cout << "after move, return the origin: " << boolalpha << result_0 << endl;

    cin.get();
    return 0;
}
