# 力扣第347题，前k个高频元素
"""
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
"""
import heapq
from queue import PriorityQueue

"""
方法一：使用堆--优先队列
先使用哈希表记录每个数字出现的次数，
然后按出现的次数将哈希表中的元素依次放入到优先队列中，
最后弹出所需要的个数。
"""
class Solution00:
    def topKFrequent(self, nums, k):
        frequent_dict = {}
        for num in nums:
            frequent_dict[num] = frequent_dict.get(num, 0) + 1
        print('frequent_dict:', frequent_dict)
        pq = []
        for ki, vi in frequent_dict.items():
            heapq.heappush(pq, (-vi, ki))
        result = [heapq.heappop(pq)[1] for _ in range(k)]
        # while pq:
        #     print(heapq.heappop(pq))

        return result


"""
方法二：基于快速排序
思路是随机选取一个数v，分成比v小和比v大的两堆
如果右边的个数等于待选个数k，则直接返回右边的堆；
如果右边的个数小于待选个数k，则将右边添加到result中，更新k为k-右边堆的大小，继续从左边堆中寻找；
如果右边的个数大于待选个数k，则k不变，继续在右边堆中寻找。
"""
class Solution01:
    def topKFrequent(self, nums, k):
        frequent_dict = {}
        for num in nums:
            frequent_dict[num] = frequent_dict.get(num, 0) + 1
        frequent_list = list(frequent_dict.items())
        print("frequent_list:", frequent_list)

        result = []
        def q_sort(li, k):
            nonlocal result
            if k == 0:
                return 
            media = li[0]
            left = []
            right = []
            for f in li[1:]:
                if f[1] <= media[1]:
                    left.append(f)
                else:
                    right.append(f)
            if len(right) == k:
                result.extend([l[0] for l in right])
                return 
            elif len(right) < k:
                result.append(media[0])
                result.extend([l[0] for l in right])
                q_sort(left, k-len(right)-1)
            else:
                q_sort(right, k)

        q_sort(frequent_list, k)
        # print('result:', result)
        return result


if __name__ == "__main__":
    nums = [4,1,-1,2,-1,2,3]
    k = 2
    # nums = [5,3,1,1,1,3,73,1]
    # k = 2
    sl0 = Solution00()
    result = sl0.topKFrequent(nums, k)
    print('result:', result)

    sl1 = Solution01()
    result = sl1.topKFrequent(nums, k)
    print('result:', result)

    # frequent_dict = {}
    # for n in nums:
    #     frequent_dict[n] = frequent_dict.get(n, 0) + 1
    # print('frequent_dict:', frequent_dict)
    # q = []
    # for k,v in frequent_dict.items():
    #     heapq.heappush(q, (k, v))
    # result = [q[i][0] for i in range(k)]
    # print('result:', result)