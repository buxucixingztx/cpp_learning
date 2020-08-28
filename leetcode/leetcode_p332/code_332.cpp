// 力扣第332题，重新安排行程
/*
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution_00{
public:
    vector<string> trips;
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> trip_dict;
    vector<string> findItinerary(vector<vector<string>>& tickets){
        for (auto & it: tickets){
            trip_dict[it[0]].emplace(it[1]);
        }
        string start = "JFK";
        dfs(start);

        reverse(trips.begin(), trips.end());
        return trips;
    };
    void dfs(const string &start){
        while (trip_dict.count(start) && trip_dict[start].size() > 0){
            string next = trip_dict[start].top();
            trip_dict[start].pop();
            // std::move函数可以一个左值强制转化为右值引用，继而可以通过右值引用使用改值，以用于移动语义。
            /*
            1、C++标准库使用比如vector::push_back等这类函数时，会对参数的对象进行复制，连数据也会复制，这就会造成对象内存的额外创建，
               本意是想把参数push_back进去就行了，通过std::move，可以避免不必要的拷贝操作。
            2、std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝，所以可以提高利用效率改善性能。
            3、对指针类型的标准库对象不需要这么做。
            */
            dfs(move(next));
        }
        trips.emplace_back(start);
    };
};

int main()
{
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    for (int i = 0; i < tickets.size(); ++i){
        for (int j = 0; j < tickets[i].size(); ++j)
            cout << tickets[i][j] << ", ";
        cout << endl;
    };
    Solution_00 sl00;
    vector<string> bt_00 = sl00.findItinerary(tickets);
    for (auto p = bt_00.begin(); p != bt_00.end(); ++p){
        if (p+1 != bt_00.end())
            cout << *p << " -> ";
        else
            cout << *p;
    }
    cout << endl;

    cin.get();
    return 0;
}



