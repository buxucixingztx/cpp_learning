# 力扣第147题，对链表进行插入排序
"""
对链表进行插入排序。

插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 
插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
"""

class ListNode:
    def __init__(self, x) -> None:
        self.val = x
        self.next = None


class Solution:
    def insertionSortList(self, head):
        if not head or not head.next:
            return head
        null_head = ListNode(0)
        null_head.next = head
        cur = head
        nt = cur.next
        while nt:
            if nt and cur.val < nt.val:
                cur = nt
                nt = cur.next
                continue
            cur.next = nt.next
            a_head = null_head
            while True:
                if a_head.next.val > nt.val:
                    nt.next = a_head.next
                    a_head.next = nt
                    break
                a_head = a_head.next
            nt = cur.next

        return null_head.next


if __name__ == "__main__":
    h = ListNode(4)
    h.next = ListNode(2)
    h.next.next = ListNode(1)
    h.next.next.next = ListNode(3)

    head = h
    while head:
        print(head.val, end='->')
        head = head.next
    
    sl = Solution()
    head = sl.insertionSortList(h)
    print()
    while head:
        print(head.val, end='->')
        head = head.next