// LCP 15. 游乐园的迷宫。
/*
小王来到了游乐园，她玩的第一个项目是模拟推销员。有一个二维平面地图，其中散布着 N 个推销点，编号 0 到 N-1，不存在三点共线的情况。
每两点之间有一条直线相连。游戏没有规定起点和终点，但限定了每次转角的方向。首先，小王需要先选择两个点分别作为起点和终点，
然后从起点开始访问剩余 N-2 个点恰好一次并回到终点。访问的顺序需要满足一串给定的长度为 N-2 由 L 和 R 组成的字符串 direction，
表示从起点出发之后在每个顶点上转角的方向。根据这个提示，小王希望你能够帮她找到一个可行的遍历顺序，输出顺序下标（若有多个方案，输出任意一种）。
可以证明这样的遍历顺序一定是存在的。


限制：

3 <= points.length <= 1000 且 points[i].length == 2
1 <= points[i][0],points[i][1] <= 10000
direction.length == points.length - 2
direction 只包含 "L","R"
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    vector<int> ptov(const vector<int>& a, const vector<int>& b){
        return vector<int> {b[0]-a[0], b[1]-a[1]};
    };

    int cross(const vector<int>& v1, const vector<int>& v2){
        // cout << "v1.size() = " << v1.size() << "  ||  v2.size() = " << v2.size() << endl;
        return v1[0]*v2[1] - v1[1]*v2[0];
    }

    vector<int> visitOrder(vector<vector<int>>& points, string direction){
        int pn = points.size();
        vector<int> visited(pn, 0);
        vector<int> orders;
        int start = 0;
        for (int i = 0; i < pn; i++){
            if (points[i][0] < points[start][0])
                start = 0;
        }
        visited[start] = 1;
        orders.emplace_back(start);

        for (auto d: direction){
            int nv = -1;
            if (d == 'L'){
              for (int i = 0; i < pn; i++){
                    if (visited[i] == 0){
                        if (nv == -1 || cross(ptov(points[start], points[nv]), ptov(points[start], points[i])) < 0)
                            nv = i;
                    }
                } 
            }
            else
            {
                for (int i = 0; i < pn; i++){
                    if (visited[i] == 0){
                        if (nv == -1 || cross(ptov(points[start], points[nv]), ptov(points[start], points[i])) < 0)
                            nv = i;
                    }
                }
            }
            start = nv;
            orders.emplace_back(start);
            visited[start] = 1;
        }

        for (int i = 0; i < pn; ++i){
            if (visited[i] == 0)
                orders.emplace_back(i);
        }

        return orders;
    }
};


int main()
{
    vector<vector<int>> points = {{1, 1}, {1, 4}, {3, 2}, {2, 1}};
    string direction = "LL";
    Solution sl;
    vector<int> orders = sl.visitOrder(points, direction);
    cout << "result:\n";
    for (int i: orders)
        cout << i << ' ';
    cout << endl;

    cin.get();
    return 0;
}

