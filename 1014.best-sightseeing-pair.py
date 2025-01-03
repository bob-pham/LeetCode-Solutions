# @leet start
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        l = len(values)
        max_score = -sys.maxsize
        for i in range(l):
            for j in range(i + 1, l):
                max_score = max(values[i] + values[j] + i - j, max_score)
        return max_score

        
# @leet end
