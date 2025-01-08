# @leet start
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        found = set()

        for i in range(2, len(s)):
            if s[i] == s[i - 2]:
                found.add(s[i-2 : i+1])

        return len(found)
        
# @leet end
