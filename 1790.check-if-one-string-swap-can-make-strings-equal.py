# @leet start
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        l1, l2 = len(s1), len(s2)
        if l1 != l2:
            return False
        if s1 == s2:
            return True

        diffs = []

        for i in range(l1):
            if s1[i] != s2[i]:
                diffs.append(i)

        if len(diffs) != 2:
            return False

        return s1[diffs[0]] == s2[diffs[1]] and s1[diffs[1]] == s2[diffs[0]]

        
# @leet end
