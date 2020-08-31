# 力扣第841题，钥匙和房间
"""
有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。

在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。

最初，除 0 号房间外的其余所有房间都被锁住。

你可以自由地在房间之间来回走动。

如果能进入每个房间返回 true，否则返回 false。
"""
import collections


"""
Solution_00是我自己想的解决方案，跟官方题解中的深度优先搜索类似，
先拿一把钥匙i打开一扇门，然后取出这扇门中的钥匙j，接着用j去开下一个门，直到下一个门已经被打开，然后返回。
"""
class Solution_00:
    def canVisitAllRooms(self, rooms):
        n = len(rooms)
        visit_rooms = [-1 for _ in range(n)]

        print('visit_rooms: ', visit_rooms)
        def open_door(key):
            if visit_rooms[key] != -1:
                return
            visit_rooms[key] = 1
            key_list = rooms[key]
            for k in key_list:
                open_door(k)

        open_door(0)
        print('rooms:', rooms)
        print('visit_rooms:', visit_rooms)
        for r in visit_rooms:
            if r == -1:
                print("can't open every door!")
                return False
        return True


"""
官方题解方法一：深度优先搜索
使用深度优先搜索的方式遍历整张图，统计可以到达的节点个数，并利用数组vis标记当前节点是否访问过，以防止重复访问。

复杂度分析
    时间复杂度：O(n+m)，其中n是房间的数量，m是所有房间中的钥匙数量的总数。
    空间复杂度：O(n)，其中n是房间的数量，主要是栈空间的开销。
"""
class Solution_01:
    def canVisitAllRooms(self, rooms):
        def dfs(key):
            nonlocal nums
            nums += 1
            visitedroom.add(key)
            key_list = rooms[key]
            for k in key_list:
                if k in visitedroom:
                    continue
                dfs(k)
        
        n = len(rooms)
        visitedroom = set()
        nums = 0
        dfs(0)
        print('s01 visitedroom:', visitedroom)
        return n == nums


"""
官方题解方法二：广度优先搜索
使用广度优先搜索的方式遍历整张图，统计可以达到的节点个数，并利用数组标记当前节点是否访问过，以防止重复访问。
"""
class Solution_02:
    def canVisitAllRooms(self, rooms):
        n = len(rooms)
        visitedroom = {0}
        nums = 0
        key_deque = collections.deque()
        key_deque.append(0)

        while key_deque:
            key = key_deque.popleft()
            nums += 1
            for k in rooms[key]:
                if k not in visitedroom:
                    # nums += 1
                    visitedroom.add(k)
                    key_deque.append(k)

        print('s02 visitedroom:', visitedroom)
        return nums == n


if __name__ == '__main__':
    # rooms = [[1], [2], [3], []]
    rooms = [[1, 3], [3, 0, 1], [2], [0]]
    s00 = Solution_00()
    result_00 = s00.canVisitAllRooms(rooms)
    print("result_00: ", result_00)

    s01 = Solution_01()
    result_01 = s01.canVisitAllRooms(rooms)
    print('result_01: ', result_01)

    s02 = Solution_02()
    result_02 = s02.canVisitAllRooms(rooms)
    print('result_02: ', result_02)

