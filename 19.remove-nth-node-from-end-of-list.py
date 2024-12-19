# @leet start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from collections import deque

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head == None:
            return None
        
        nodes = deque()
        sz = max(3, n + 1)
        curr = head
        while curr != None:
            nodes.append(curr)
            if len(nodes) > sz:
                nodes.popleft()
            curr = curr.next

        if len(nodes) == 1:
            return None
        
        if len(nodes) == 2:
            nodes[0].next = None
            nodes[1].next = None
            return nodes[n-1]

        while len(nodes) < 3:
            nodes.append(None)
        
        nodes[0].next = nodes[2]

        return head

        
# @leet end
