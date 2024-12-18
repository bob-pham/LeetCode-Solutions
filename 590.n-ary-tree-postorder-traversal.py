# @leet start
"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        result = []
        self.postorderHelper(root, result)
        return result

    def postorderHelper(self, node, result):
        if node == None:
            return
        if node.children != None:
            for child in node.children:
                self.postorderHelper(child, result)
        result.append(node.val)
        
# @leet end
