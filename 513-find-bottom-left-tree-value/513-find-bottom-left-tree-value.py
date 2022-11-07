# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        queue1 = deque()
        queue2 = deque()
        queue3 = deque()
        
        queue1.append(root)
        
        while queue1:
            curr = queue1.popleft()
            queue3.append(curr)
            if curr.left:
                queue2.append(curr.left)
            if curr.right:
                queue2.append(curr.right)
                
            if not queue1:
                queue1, queue2 = queue2, deque()
            
                if queue1:
                    queue3 = deque()
           
        return queue3.popleft().val