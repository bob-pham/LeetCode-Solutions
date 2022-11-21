class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        curr_max = 0 if nums[0] > nums[1] else 1
        prev_max = 0 if nums[0] < nums[1] else 1
        dominant = nums[prev_max] * 2 <= nums[curr_max]
        
        for i in range(2, len(nums)):
            if nums[i] < nums[curr_max]:
                if nums[i] > nums[prev_max]:
                    dominant = nums[i] * 2 <= nums[curr_max]
                    prev_max = i
            elif nums[i] > nums[curr_max]:
                prev_max, curr_max = curr_max, i
                dominant = nums[prev_max] * 2 <= nums[curr_max]
        
        return curr_max if dominant else -1

                    

