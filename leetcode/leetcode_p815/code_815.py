# 力扣第815题，公交路线
"""
我们有一系列公交路线。每一条路线 routes[i] 上都有一辆公交车在上面循环行驶。
例如，有一条路线 routes[0] = [1, 5, 7]，表示第一辆 (下标为0) 公交车会一直按照 1->5->7->1->5->7->1->... 的车站路线行驶。

假设我们从 S 车站开始（初始时不在公交车上），要去往 T 站。 
期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1 表示不可能到达终点车站。
"""
import collections

# routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]]
# S = 15
# T = 12

routes = [[1,7],[3,5]]
S = 5
T = 5

class Solution:
    def numBusesToDestination(self, route, S: int, T: int) -> int:
        if S == T:
            return 0
        length = len(routes)
        visited = [0] * length

        record = collections.defaultdict(list)
        out_deg = collections.defaultdict(set)

        for i, route in enumerate(routes):
            for station in route:
                if len(record[station]) != 0:
                    for r in record[station]:
                        out_deg[i].add(r)
                        out_deg[r].add(i)
                record[station].append(i)

        start_route = record[S]
        end_route = record[T]

        if not start_route or not end_route:
            return -1

        i = 1
        while start_route:
            next_start_route = []
            for s in start_route:
                if visited[s]:
                    continue
                else:
                    visited[s] = 1
                if s in end_route:
                    return i
                next_start_route.extend(out_deg[s])
            i += 1
            start_route = next_start_route
        return -1


if __name__ == "__main__":
    pass
