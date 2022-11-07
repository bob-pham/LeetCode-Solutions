# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        vals = []
        result = 0
        
        while (head):
            vals.append(head.val)
            head = head.next

        for x in range(len(vals)):
            result = max(result, vals[x] + vals[len(vals) - 1 - x])
                
        return result