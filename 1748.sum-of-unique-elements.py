# @leet start
class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        result = 0
        counts = Counter(nums)
        for count in counts:
            if counts[count] == 1:
                result += count
        return result
        
# @leet end
