class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        past = {}
        
        for i in range(0, len(nums)):
            x = nums[i]
            sol = target - x
            if (sol in past):
                return [i, past[sol]]
            past[x] = i 
        return []