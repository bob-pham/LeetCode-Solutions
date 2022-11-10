# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.target = targetSum
        return self.pathSumFinder(root, [])
    
    def pathSumFinder(self, node, paths):
        if not node:
            return 0
        
        found = 1 if node.val == self.target else 0
        
        for i in range(len(paths)):
            paths[i] += node.val
            if paths[i] == self.target:
                found += 1
                        
        paths.append(node.val)
        
        return found + self.pathSumFinder(node.left, paths.copy()) + self.pathSumFinder(node.right, paths.copy())
        