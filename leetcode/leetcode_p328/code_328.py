# 力扣第328题，奇偶链表
"""
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数.
"""

class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        evenhead = ListNode()
        evennext = evenhead
        
        oddnext = head
        next_node = head.next

        i = 1
        while next_node:
            i += 1
            if i % 2 == 0:
                evennext.next = next_node
                evennext = evennext.next
            else:
                oddnext.next = next_node
                oddnext = oddnext.next
            next_node = next_node.next
        evennext.next = None
        oddnext.next = evenhead.next
        return head
