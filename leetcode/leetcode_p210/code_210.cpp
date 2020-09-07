// 力扣第210题，课程表II
/*
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
*/
#include <iostream>

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


// 深度优先遍历
class Solution_00{
public:
    vector<int> result;     // 记录结果
    unordered_map<int, vector<int>> course_dict;    // 
    vector<int> recoder;    // 
    bool valid = true;      // 标记是否有效，即是否有环
    vector<int> findOrder(int numCourses, vector<vector<int>> & prerequisites) {
        for (int i = 0; i < numCourses; i++)
            recoder.push_back(0);
        for (auto p = prerequisites.begin(); p != prerequisites.end(); ++p){
            course_dict[(*p)[1]].push_back((*p)[0]);
        }
        for (int i = 0; i < numCourses; i++)
            dfs(i);
        
        if (!valid || result.size() != numCourses)
            return {};
        
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(int index){
        if (recoder[index] == 2)
            return;
        vector<int> out = course_dict[index];
        recoder[index] = 1;
        for (auto p = out.begin(); p != out.end(); ++p){
            if (recoder[*p] == 1)
            {
              valid = false;
                return;  
            }
            else if (recoder[*p] == 0)
                dfs(*p);
        }
        recoder[index] = 2;
        result.push_back(index);
    }
};


class Solution_01{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> deg(numCourses, 0);
        unordered_map<int, vector<int>> outdeg;
        queue<int> zerodeg;
        vector<int> result;
        for (auto p = prerequisites.begin(); p != prerequisites.end(); ++p){
            outdeg[(*p)[1]].push_back((*p)[0]);
            deg[(*p)[0]] += 1;
        }
        for (int d = 0; d < deg.size(); ++d){
            if (deg[d] == 0)
                zerodeg.emplace(d);
        }
        while (!zerodeg.empty()){
            int index = zerodeg.front();
            zerodeg.pop();
            result.push_back(index);
            vector<int> outlist = outdeg[index];
            for (auto p = outlist.begin(); p != outlist.end(); ++p){
                deg[*p] -= 1;
                if (deg[*p] == 0)
                    zerodeg.emplace(*p);
            }
        }
        if (result.size() != numCourses)
            return {};
        return result;
    }
};


int main()
{
    vector<int> a{1, 3, 5, 6};
    cout << "before reverse a:" << endl;
    for(auto p = a.begin(); p != a.end(); p++)
        cout << *p << ' ';
    cout << endl;

    reverse(a.begin(), a.end());
    cout << "after reverse a:" << endl;
    for (auto p = a.begin(); p != a.end(); p++)
        cout << *p << ' ';
    cout << endl;

    int n = 4;
    vector<vector<int>> pres{{1,0},{2,0},{3,1},{3,2}};
    Solution_00 sl0;
    vector<int> order0 = sl0.findOrder(n, pres);
    cout << "order0: " << endl;
    for (auto p = order0.begin(); p != order0.end(); ++p)
        cout << *p << ' ';
    cout << endl;

    Solution_01 sl1;
    vector<int> order1 = sl1.findOrder(n, pres);
    cout << "order: " << endl;
    for (auto p = order1.begin(); p != order1.end(); ++p)
        cout << *p << ' ';
    cout << endl;

    // vector<int> deg(5, 0);
    // cout << "deg.size(): " << deg.size() << endl;
    // for (auto p = deg.begin(); p != deg.end(); ++p)
    //     cout << "*p: " << *p << endl;

    cin.get();
    return 0;
}
