# @leet start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        global_max, curr_max = nums[0], nums[0]

        for i in range(1, len(nums)):
            val = nums[i]
            if curr_max < 0:
                curr_max = max(curr_max, val)
            else:
                curr_max += val
                curr_max = max(0, curr_max)
            
            global_max = max(curr_max, global_max)

        return global_max
        
# @leet end
