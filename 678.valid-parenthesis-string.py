# @leet start
from collections import deque
class Solution:
    def checkValidString(self, s: str) -> bool:
        stars = deque()
        left  = deque()

        for i, paren in enumerate(s):
            if paren == "*":
                stars.append(i)
            elif paren == "(":
                left.append(i)
            elif paren == ")":
                if len(left) > 0:
                    left.pop()
                elif len(stars) > 0:
                    stars.pop()
                else:
                    return False

        if len(left) == 0:
            return True

        if len(left) < len(stars):
            return False

        while len(left) > 0 and len(stars) > 0:
            left_idx = left.pop()
            if stars[-1] < left_idx:
                return False
            stars.pop()


        return len(left) == 0
        
# @leet end
