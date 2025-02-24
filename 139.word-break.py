# @leet start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        for i in range(len(wordDict)):
            s2 = s2.replace(wordDict[i], " ")
            if s2.replace(" ", "") == "":
                return True

            if self.wordBreak(s2, wordDict[i] + wordDict[i + 1:]):
                return True

        return False
# @leet end
