# @leet start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        results = []
        todo = deque()

        curr_max = -sys.maxsize
        curr_level = 0

        todo.append((root, 0))

        while len(todo) > 0:
            node, level = todo.popleft()

            if level != curr_level:
                results.append(curr_max)
                curr_level = level
                curr_max = node.val

            curr_max = max(curr_max, node.val)

            if node.left != None:
                todo.append((node.left, level + 1))
            if node.right != None:
                todo.append((node.right, level + 1))

        results.append(curr_max)

        return results
# @leet end
