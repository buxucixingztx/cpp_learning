// 力扣第841题，钥匙和房间
/*
有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。

在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。

最初，除 0 号房间外的其余所有房间都被锁住。

你可以自由地在房间之间来回走动。

如果能进入每个房间返回 true，否则返回 false。
*/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution_00{
private:
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n = rooms.size();
        vector<int> visited_rooms(n, -1);
        openDoor(rooms, visited_rooms, 0);
        for (auto p = visited_rooms.begin(); p != visited_rooms.end(); ++p){
            if (*p == -1)
                return false;
        }
        return true;
    }
    void openDoor(vector<vector<int>>& rooms, vector<int> & visited_rooms, int key){
        if (visited_rooms[key] != -1)
            return;
        visited_rooms[key] = 1;
        vector<int> key_list = rooms[key];
        for (auto p = key_list.begin(); p != key_list.end(); ++p)
            openDoor(rooms, visited_rooms, *p);
    }
};


class Solution_01{
public:
    vector<int> visited_rooms;
    int num;

    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n = rooms.size();
        num = 0;
        visited_rooms.resize(n);
        dfs(rooms, 0);
        return num == n;
    }

    void dfs(vector<vector<int>>& rooms, int key){
        num++;
        visited_rooms[key] = true;
        for (auto p = rooms[key].begin(); p != rooms[key].end(); ++p){
            if (!visited_rooms[*p])
                dfs(rooms, *p);
        }
    }
};


class Solution_02{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n = rooms.size();
        vector<int> visited_room(n, -1);
        int nums = 0;
        deque<int> key_list;
        key_list.push_back(0);

        while (!key_list.empty())
        {
            nums++;
            int key = key_list.front();
            // cout << "nums: " << nums << ";  key: " << key << endl;
            key_list.pop_front();
            visited_room[key] = 1;
            for (auto p = rooms[key].begin(); p != rooms[key].end(); ++p){
                // cout << "*p: " << *p << endl;
                if (visited_room[*p] == -1){
                    key_list.push_back(*p);
                    visited_room[*p] = 1;
                    // nums++;
                }
            }
        }
        // cout << "nums: " << nums << endl;
        return nums == n;
    }
};


int main()
{
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    // vector<vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    int n = rooms.size();
    Solution_00 s00;
    bool result00 = s00.canVisitAllRooms(rooms);
    cout << "the result00 if visit all rooms: " << boolalpha << result00 << endl;
    
    Solution_01 s01;
    bool result01 = s01.canVisitAllRooms(rooms);
    cout << "the result01 if visit all rooms: " << boolalpha << result01 << endl;

    Solution_02 s02;
    bool result02 = s02.canVisitAllRooms(rooms);
    cout << "the result02 if visit all rooms: " << boolalpha << result02 << endl;

    cin.get();
    return 0;
}
