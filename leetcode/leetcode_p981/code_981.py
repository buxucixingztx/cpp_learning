# 力扣第981题，基于时间的键值存储
"""
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
"""
from collections import defaultdict
import bisect


"""
使用字典保存key, value, 因为时间戳是严格递增的，所以我们直接append就可以得到一个递增序列，
然后使用二分查找，查找对应的位置，取出对应位置的值
"""
class TimeMap:
    def __init__(self) -> None:
        """
        Initialize your data structure here.
        """
        self.keydict = defaultdict(list)

    def set(self, key, value, timestamp):
        self.keydict[key].append((timestamp, value))

        
    def get(self, key, timestamp):
        vt = self.keydict.get(key)
        if not vt:
            return ''
        i = bisect.bisect(vt, (timestamp, chr(127)))
        return vt[i-1][1] if i else ''


if __name__ == "__main__":
    li = [1, 4, 8, 9]
    print(li)

    li.insert(6, 3)
    print(li)