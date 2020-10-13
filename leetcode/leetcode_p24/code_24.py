# 力扣第24题，两两交换链表中的节点
"""
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换.
"""

class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        cur = head
        head = head.next
        next_node = cur.next

        temp = ListNode()
        while next_node:
            cur.next = next_node.next
            next_node.next = cur
            temp.next = next_node
            temp = cur
            
            cur = cur.next
            if not cur:
                break
            next_node = cur.next

        return head


class Solution_01:
    def swapPairs(self, head: ListNode) -> ListNode:
        def dfs(node):
            if not node or not node.next:
                return node
            new_head = node.next
            next_node = dfs(new_head.next)
            new_head.next = node
            node.next = next_node
            return new_head
        return dfs(head)


