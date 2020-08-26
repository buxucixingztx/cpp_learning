# 这是别人用python实现的几种很优秀的解题思路

from collections import deque

array = [4, 6, 7, 7]


"""
解法一：动态规划+哈希表
1、初始化集合中第一个元素 {(nums[0], )}
2、用集合pres来保存每一个递增的元素
3、去除元素个数为1的数组
"""
class Solution_00:
    def findSubsequences(self, nums):
        if not nums:
            return []
        pres = {(nums[0], )}
        for i in nums[1:]:
            pres.update({j+(i, ) for j in pres if j[-1] <= i})
            pres.add((i, ))
        return [list(i) for i in pres if len(i) > 1]


"""
解法二：深度优先搜索+哈希表
1、定义返回列表res保存所有递增子序列；
2、深度优先搜索(dfs)，参数: nums, tmp保存当前递增子序列；
    如果当前递增子序列符合要求：res增加tmp
    定义集合保存状态，避免重复；
    inx, i 循环nums的索引值对。
        如果当前值在以前已被遍历：
            跳出当前循环，开始下一次循环。
        如果i加入tmp可以形成递增子序列：
            i为键，1位置加入集合；
            递归：
                nums = nums[inx+1:]
                tmp = tmp + [i]
3、调用dfs:
    nums = nums
    tmp = []
4、返回res
"""
class Solution_01:
    def findSubsequences(self, nums):
        res = []

        def dfs(nums, tmp):
            if len(tmp) > 1:
                res.append(tmp)
            curPres = set()
            for inx, i in enumerate(nums):
                if i in curPres:
                    continue
                if not tmp or i >= tmp[-1]:
                    curPres.add(i)
                    dfs(nums[inx+1:], tmp+[i])

        dfs(nums, [])
        return res


"""
解法三：广度优先搜索+哈希表
1、初始化一个队列d，将[(nums, [])]作为初始值，nums存放待求数组，[]用来存放已有构建的数组
2、当d不为空时，开始从左侧弹出元素
3、如果元素的第二个数组长度大于1，添加到结果中
4、初始化一个集合，用于避免重复
5、遍历元素第一个数组：
    如果该数组的元素出现在集合中，则跳过本次循环
    如果可以构成递增数组，则将该元素添加到集合，并将(cur[ind+1:], new+[i])添加到队列当中
"""
class Solution_02:
    def findSubsequences(self, nums):
        res = []
        d = deque([(nums, [])])
        while d:
            cur, new = d.popleft()
            if len(new) > 1:
                res.append(new)
            curPres = set()
            for inx, i in enumerate(cur):
                if i in curPres:
                    continue
                if not new or i >= new[-1]:
                    curPres.add(i)
                    d.append((cur[inx+1:], new+[i]))
        return res

