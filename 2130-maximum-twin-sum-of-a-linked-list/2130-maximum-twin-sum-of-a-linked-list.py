# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        queue = deque()
        stack = deque()
        length = 0
        result = 0
        
        while (head):
            queue.append(head.val)
            stack.append(head.val)
            head = head.next
            length += 1

        for i in range(length // 2):
            result = max(result, queue.popleft() + stack.pop())

        return result