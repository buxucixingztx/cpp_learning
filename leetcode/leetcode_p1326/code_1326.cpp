// 力扣第1326题，灌溉花园的最少水龙头数目
/*
在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。

花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。

给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，其中 ranges[i] （下标从 0 开始）表示：如果打开点 i 处的水龙头，
可以灌溉的区域为 [i -  ranges[i], i + ranges[i]] 。

请你返回可以灌溉整个花园的 最少水龙头数目 。如果花园始终存在无法灌溉到的地方，请你返回 -1 。
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution_00{
public:
    int minTaps(int n, vector<int> & ranges){
        vector<int> prev;
        for (int i = 0; i <= n; ++i)
            prev.push_back(i);
        for (int i = 0; i <= n; ++i){
            int lv = max(0, i-ranges[i]);
            int rv = min(n, i+ranges[i]);
            prev[rv] = min(lv, prev[rv]);
        }

        int breakpoint = n;
        int thresh = n+1;
        int ans = 0;
        for (int i = n; i > 0; --i){
            thresh = min(thresh, prev[i]);
            if (breakpoint == i){
                if (i <= thresh)
                    return -1;
                ans++;
                breakpoint = thresh;
            }
        }
        cout << "answer: " << ans << endl;
        return ans;
    }
};

int main()
{
    int n = 5;
    vector<int> ranges = {3, 4, 1, 1, 0, 0};
    Solution_00 sl0;
    sl0.minTaps(n, ranges);

    cin.get();
    return 0;
}