# @leet start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        global_max = nums[0]
        local_max = nums[0]

        for i in range(1, len(nums)):
            val = nums[i]
            if local_max < 0:
                local_max = max(val, local_max)
            else:
                local_max += val
            global_max = max(global_max, local_max)
        return global_max
# @leet end
