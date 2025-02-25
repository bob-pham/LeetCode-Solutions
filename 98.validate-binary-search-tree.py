# @leet start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def validBSTHelper(node, curr_max, curr_min):
            if node == None:
                return True
            
            if node.val > curr_max or node.val < curr_min:
                return False

            return validBSTHelper(node.left, node.val, curr_min) and validBSTHelper(node.right, curr_max, node.val)

        return validBSTHelper(root, sys.maxsize, -sys.maxsize)
# @leet end
