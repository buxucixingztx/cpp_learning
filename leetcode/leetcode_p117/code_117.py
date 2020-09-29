# 力扣第117题，填充每个节点的下一个右侧节点指针II
"""
给定一个二叉树
struct Node{
    int val;
    Node* left;
    Node* right;
    Node* next;
}

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

进阶：
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
"""
import collections
from collections import deque

class Node:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None
        self.next = None


""" 自己实现的，广度优先遍历搜索，
使用队列来保存每一个节点，及这个节点的层数，
然后取元素的时候，先把这个节点的左右子树放进去，观察这个节点的层数是否与下一个元素的层数一致。
"""
class Solution:
    def connect(self, root):
        node_dq = collections.deque()
        node_dq.append([root, 0])

        while len(node_dq) != 0:
            node = node_dq.popleft()
            index = node[1]
            if node[0].left:
                node_dq.append([node[0].left, index+1])
            if node[0].right:
                node_dq.append([node[0].right, index+1])
            if len(node_dq) > 0 and node_dq[0][1] == index:
                node[0].next = node_dq[0][0]
        return root


""" 可以使用三个指针在常量空间内解决问题， 
思路是使用上层节点来指导下层节点进行连接。
"""
class Solution_01:
    def connect(self, root):
        node = root
        while node:
            last = None
            start = None
            while node:
                if node.left:
                    if last:
                        last.next = node.left
                    last = node.left
                    if not start:
                        start = node.left
                if node.right:
                    if last:
                        last.next = node.right
                    last = node.right
                    if not start:
                        start = node.right
                node = node.next
            node = start
        return root


if __name__ == "__main__":
    dq = collections.deque()
    for i in range(5):
        dq.append(i)
    # print(dq.pop())
    # print(dq.pop())
    # print(dq.pop())
    print(dq[0])