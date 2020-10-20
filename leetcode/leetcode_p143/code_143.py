# 力扣第143题，重排链表
"""
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
"""
import collections

class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head):
        if not head:
            return 
        record = []
        cur = head
        while cur:
            record.append(cur)
            cur = cur.next

        cur = record.pop(0)
        while record:
            cur.next = record.pop()
            cur = cur.next
            if len(record) == 0:
                break
            cur.next = record.pop(0)
            cur = cur.next
        cur.next = None


class Solution:
    def reorderList(self, head):
        if not head:
            return 
        record = collections.deque()
        cur = head
        while cur:
            record.append(cur)
            cur = cur.next

        cur = record.popleft()
        while record:
            cur.next = record.pop()
            cur = cur.next
            if len(record) == 0:
                break
            cur.next = record.popleft()
            cur = cur.next
        cur.next = None


if __name__ == "__main__":
    pass