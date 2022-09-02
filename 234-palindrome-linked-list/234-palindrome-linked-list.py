# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        nodes = deque()
        curr = head
        length = 0
        
        while (curr):
            nodes.append(curr)
            curr = curr.next
            length += 1
            
        for i in range((int) (length / 2)):
            if (nodes.pop().val != nodes.popleft().val):
                return False
        
        return True
            