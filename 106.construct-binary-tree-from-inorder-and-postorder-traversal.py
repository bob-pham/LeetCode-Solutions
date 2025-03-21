# @leet start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:

        if not inorder or not postorder:
            return None

        root = TreeNode(postorder[-1])
        idx = inorder.index(postorder[-1])
        l = len(inorder)

        root.right = self.buildTree(inorder[idx+1:], postorder[idx-l:-1])
        root.left = self.buildTree(inorder[:idx], postorder[:idx])

        return root
        
# @leet end
