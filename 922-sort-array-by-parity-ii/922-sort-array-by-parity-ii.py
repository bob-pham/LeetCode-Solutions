class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        
        odd, even = 1, 0
        length = len(nums)
        
        while (odd < length and even < length):
            while (odd < length and nums[odd] % 2):
                odd += 2
            
            if odd >= length:
                break
            
            while (even < length and nums[even] % 2 == 0):
                even += 2
            
            nums[odd], nums[even] = nums[even], nums[odd]
            
            odd += 2
            even += 2
        
        return nums