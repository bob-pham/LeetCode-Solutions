# @leet start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        curr = []
        zag = False
        level = 0

        todo = deque()
        todo.append((root, 0))

        while len(todo) > 0:
            c, i = todo.popleft()

            if c == None:
                continue

            if i != level:
                if zag:
                    result.append(curr[::-1])
                else:
                    result.append(curr)
                curr = []
                zag = not zag
                level = i

            curr.append(c.val)

            todo.append((c.left, i + 1))
            todo.append((c.right, i + 1))

        if curr:
            if zag:
                result.append(curr[::-1])
            else:
                result.append(curr)

        return result


# @leet end
