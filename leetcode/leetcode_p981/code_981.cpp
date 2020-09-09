// 力扣第981题，基于时间的键值存储
/*
创建一个基于时间的键值存储类 TimeMap，它支持下面两个操作：

1. set(string key, string value, int timestamp)

存储键 key、值 value，以及给定的时间戳 timestamp。
2. get(string key, int timestamp)

返回先前调用 set(key, value, timestamp_prev) 所存储的值，其中 timestamp_prev <= timestamp。
如果有多个这样的值，则返回对应最大的  timestamp_prev 的那个值。
如果没有值，则返回空字符串（""）。

提示：

所有的键/值字符串都是小写的。
所有的键/值字符串长度都在 [1, 100] 范围内。
所有 TimeMap.set 操作中的时间戳 timestamps 都是严格递增的。
1 <= timestamp <= 10^7
TimeMap.set 和 TimeMap.get 函数在每个测试用例中将（组合）调用总计 120000 次。
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class TimeMap{
public:
    unordered_map<string, vector<int>> keytime;
    unordered_map<string, vector<string>> keyvalue;
    TimeMap(){
        keyvalue.clear();
        keytime.clear();
    };

    void set(string key, string value, int timestamp){
        keytime[key].emplace_back(timestamp);
        keyvalue[key].emplace_back(value);
    };

    string get(string key, int timestamp){
        vector<int> time = keytime[key];
        vector<string> value = keyvalue[key];
        if (time.size() == 0)
            return "";
        int index = upper_bound(time.begin(), time.end(), timestamp) - time.begin();
        if (index == 0)
            return "";
        return value[index-1];
    }
};


int main()
{
    unordered_map<string, vector<int>> kt;
    // cout << "kt.at(\"aa\")" << k
    // TimeMap tm;
    // tm.set("foo", "bar", 1);
    // string value = tm.get("foo", 2);
    // cout << "value: " << value << endl;
    vector<int> vv = {1, 4, 5, 7, 9, 21, 34};
    int v = 0;
    vector<int>::iterator iter = upper_bound(vv.begin(), vv.end(), v);
    int index = iter - vv.begin();
    cout << "*iter = " << *iter << endl;
    cout << "index = " << index << endl;

    cin.get();
    return 0;
}