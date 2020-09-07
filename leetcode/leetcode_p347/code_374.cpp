// 力扣第347题，前k个高频元素
/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


// 方法一：使用优先队列
class Solution_00{
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2){
        return p1.second > p2.second;
    };
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int, int> frequent_dict;
        for (int num: nums)
            frequent_dict[num]++;
        for (auto p = frequent_dict.begin(); p != frequent_dict.end(); ++p){
            cout << (*p).first << ": " << (*p).second << endl;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp) > pq(cmp);
        for (auto&[num, count]: frequent_dict){
            if (pq.size() == k){
                if (pq.top().second < count) {
                    pq.pop();
                    pq.emplace(num, count);
                }
            } else {
                pq.emplace(num, count);
            }
        }

        vector<int> result;
        while (!pq.empty()){
            result.emplace_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};


// 方法二：基于快速排序
class Solution_01{
public:
    void qsort(vector<pair<int, int>> num_count, int start, int end, int k, vector<int> &ret){
        if (k == 0)
            return;
        int median = (start+end)/2;
        int median_count = num_count[median].second;
        swap(num_count[start], num_count[median]);
        int index = start;
        for (int i = start+1; i <= end; i++){
            if (num_count[i].second > median_count){
                swap(num_count[index], num_count[i]);
                index++;
            }
        }
        if (k == index-start){
            for (int i = start; i < index; ++i)
                ret.emplace_back(num_count[i].first);
        }
        else if (k < index-start)
            qsort(num_count, start, index-1, k, ret);
        else {
            for (int i = start; i <= index; ++i){
                ret.emplace_back(num_count[i].first);
            }
            qsort(num_count, index+1, end, k-(index-start+1), ret);
        }
    }
    vector<int> topKFrequent(vector<int> nums, int k){
        unordered_map<int, int> frequent_dict;
        for (auto num: nums)
            frequent_dict[num]++;
        vector<pair<int, int>> frequent_list;
        for (auto &[num, count]: frequent_dict)
            frequent_list.emplace_back(num, count);
        vector<int> result;
        int end = nums.size()-1;
        qsort(frequent_list, 0, end, k, result);

        return result;
    }
};


int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    // Solution_00 sl0;
    // vector<int> result00 = sl0.topKFrequent(nums, k);
    // cout << "result_00:" << endl;
    // for (int r: result00)
    //     cout << r << " ";
    // cout << endl;

    Solution_01 sl1;
    vector<int> result01 = sl1.topKFrequent(nums, k);
    cout << "result_01: " << endl;
    for (int r: result01)
        cout << r << ' ';
    cout << endl;

    cin.get();
    return 0;
}