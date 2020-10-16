# 力扣第621题，任务调度器
"""
给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。
任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。

然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

你需要计算完成所有任务所需要的最短时间。
"""

class Solution:
    def leastInterval(self, tasks, n):
        length = len(tasks)
        count = dict()
        max_count = 0
        for task in tasks:
            count[task] = count.get(task, 0) + 1
            if count[task] > max_count:
                max_count = count[task]
        total_time = (max_count - 1) * (n+1)
        for k,v in count.items():
            total_time += max(0, v-max_count+1)
        return max(total_time, length)


if __name__ == "__main__":
    pass
    