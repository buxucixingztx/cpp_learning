# 力扣第82题，删除排序链表中的重复元素II

"""
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
"""

class ListNode:
    def __init__(self, x) -> None:
        self.val = x
        self.next = None


class Solution:
    def deleteDuplicates(self, head):
        null_head = ListNode(0)
        null_head.next = head
        
        cur_node = null_head
        next_node = cur_node.next
        while next_node:
            flag = False
            while next_node.next and next_node.val == next_node.next.val:
                next_node = next_node.next
                cur_node.next = next_node.next 
                flag = True
            if flag:
                next_node = cur_node.next
                continue
            cur_node = next_node
            next_node = cur_node.next
        
        return null_head.next
            

