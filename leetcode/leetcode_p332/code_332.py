# 力扣第332题，重新安排行程
"""
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。
"""
import collections
import heapq


# tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
# tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
tickets = [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]


"""
自己写的函数一直超时
"""
def findItinerary_00(tickets):
    all_trips = []
    def find_trip(tickets, start):
        print("start:", start, 'tickets:', tickets, 'all_trips:', all_trips)
        if len(tickets) == 0:
            all_trips.append(start)
            return []
        valid_list = []
        for i,ticket in enumerate(tickets):
            if ticket[0] == start[-1]:
                valid_list.append([i, ticket[1]])

        if len(valid_list) == 0:
            all_trips.append(start)
            return []
        print('valid_list:', valid_list)
        for valid in valid_list:
            left_tickets = tickets[:valid[0]] + tickets[valid[0]+1:]
            new_start = start + [valid[1]]
            # print('start: ', start, 'tickets:', left_tickets)
            find_trip(left_tickets, new_start)


    start = ['JFK']
    find_trip(tickets, start)

    length = len(tickets) + 1
    final_trip = ['zzz']
    print('all_trips: ', all_trips)
    for trip in all_trips:
        if len(trip) != length:
            continue
        if final_trip > trip:
            final_trip = trip


    print('finally trip:', final_trip)


"""
试一下官方代码
注：官方代码思路确实比较好，使用深度优先遍历，先找到最后的地点，向上回溯
"""

vect = collections.defaultdict(list)
for depart, arrive in tickets:
    vect[depart].append(arrive)
print(vect)
for key in vect:
    heapq.heapify(vect[key])
print(vect)

stack = list()
def dfs(curr):

    while vect[curr]:
        tmp = heapq.heappop(vect[curr])
        dfs(tmp)
    stack.append(curr)

dfs('JFK')
print(stack)