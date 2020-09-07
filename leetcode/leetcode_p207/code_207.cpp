// 力扣第207题，课程表
/*
你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution_00{
public:
    bool valid = true;
    unordered_map<int, vector<int>> outdeg;
    // vector<int> states;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> states(numCourses, 0);
        for (auto p = prerequisites.begin(); p != prerequisites.end(); ++p)
            outdeg[(*p)[1]].push_back((*p)[1]);

        for (int i = 0; i < numCourses; i++)
            dfs(i, states);

        return valid;
    }

    void dfs(int index, vector<int> &states){
        // cout << "index: " << index << " | states[index]: " << states[index] << endl;
        if (states[index] == 2 || !valid)
            return;
        vector<int> outs = outdeg[index];
        states[index] = 1;
        for (auto p = outs.begin(); p != outs.end(); ++p){
            if (states[(*p)] == 1){
                valid = false;
                return;
            }
            else if(states[(*p)] == 0)
                dfs((*p), states);
        }
        states[index] = 2;
    }
};


class Solution_01{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> num_indeg(numCourses, 0);
        unordered_map<int, vector<int>> outdeg;
        queue<int> zero_q;
        int nums = 0;

        for (auto p = prerequisites.begin(); p != prerequisites.end(); p++){
            outdeg[(*p)[1]].push_back((*p)[0]);
            num_indeg[(*p)[0]]++;
        }

        for (int i = 0; i < num_indeg.size(); ++i){
            if (num_indeg[i] == 0)
                zero_q.emplace(i);
        }

        while (!zero_q.empty()){
            nums++;
            int index = zero_q.front();
            zero_q.pop();

            vector<int> outs = outdeg[index];
            for (auto p = outs.begin(); p != outs.end(); ++p){
                num_indeg[*p]--;
                if (num_indeg[*p] == 0)
                    zero_q.emplace(*p);
            }
        }

        return nums == numCourses;
    }
};


int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1,0},{1,2},{0,1}};
    // int numCourses = 4;
    // vector<vector<int>> prerequisites = {{0,1},{3,1},{1,3},{3,2}};

    Solution_00 sl0;
    bool result0 = sl0.canFinish(numCourses, prerequisites);
    cout << "result0: " << boolalpha << result0 << endl;

    Solution_01 sl1;
    bool result1 = sl1.canFinish(numCourses, prerequisites);
    cout << "result1: " << boolalpha << result1 << endl;

    cin.get();
    return 0;
}