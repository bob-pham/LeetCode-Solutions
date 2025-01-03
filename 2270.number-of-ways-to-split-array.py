# @leet start
class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        result = 0
        left_sum, right_sum = 0, sum(nums)

        for i in range(0, len(nums) - 1):
            left_sum += nums[i]
            right_sum -= nums[i]
            if left_sum >= right_sum:
                result += 1

        return result

        
# @leet end
