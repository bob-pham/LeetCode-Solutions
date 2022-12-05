# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        middle = 0
        
        curr = head
        
        while (curr):
            curr = curr.next
            middle += 1

        curr = head
        middle = middle // 2
            
        for i in range(middle):
            curr = curr.next
        
        return curr
        