# 力扣第2题，两数相加
"""
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
"""
class ListNode:
    def __init__(self, x) -> None:
        self.val = x
        self.next = None

"""
思路是将两个链表从头开始依次相加，如果大于10就进位，如果某个链表长度不够，就补0
"""
class Solution_00:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l = ListNode(0)
        first = l
        carry = 0
        while l1 != None or l2 != None:
            if l1 == None:
                l1 = ListNode(0)
            elif l2 == None:
                l2 = ListNode(0)
            val = (l1.val + l2.val + l.val) % 10
            carry = (l1.val + l2.val + l.val) // 10
            l.val = val
            if l1.next == None and l2.next == None:
                break
            l.next = ListNode(carry)
            l = l.next
            l1 = l1.next
            l2 = l2.next
        if carry != 0:
            l.val = l.val % 10
            l.next = ListNode(carry)

        return first



