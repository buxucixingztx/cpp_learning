# 力扣第57题，插入区间
"""
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
"""


"""
一力降十会，暴力匹配，
重点是各种情况的判断。
"""
def insert(intervals, newInterval):

    start_flag = False
    start = newInterval[0]
    end = newInterval[1]
    if start < intervals[0][0]:
        start_flag = True
    new_list = []
    for index, value in enumerate(intervals):
        if start_flag:
            if value[0] > end:
                new_list.append([start, end])
                new_list.extend(intervals[index:])
                break
            elif value[0] == end:
                intervals[index] = [start, value[1]]
                new_list.extend(intervals[index:])
                break
            elif value[0] < end <= value[1]:
                intervals[index] = [start, value[1]]
                new_list.extend(intervals[index:])
                break
        else:
            if value[0] <= start <= value[1]:
                if end < value[1]:
                    new_list.extend(intervals[index:])
                    break
                else:
                    start_flag = True
                    start = value[0]
            elif value[1] < start:
                new_list.append(value)
            elif start < value[0]:
                if end < value[0]:
                    new_list.append([start, end]) 
                    new_list.extend(intervals[index:])
                    break
                elif end <= value[1]:
                    intervals[index] = [start, value[1]]
                    new_list.extend(intervals[index:])
                    break
                start_flag = True
    else:
        new_list.append([start, end])

    return new_list


if __name__ == "__main__":

    # intervals = [[1,3],[6,9]]
    # newInterval = [2,5]
    intervals = [[3,6],[9,9],[11,13],[14,14],[16,19],[20,22],[23,25],[30,34],[41,43],[45,49]]
    newInterval = [29,32]
    new_list = insert(intervals, newInterval)
    # print('start_flag:', start_flag)
    # print('intervals: ', intervals)
    print('new_list:', new_list)