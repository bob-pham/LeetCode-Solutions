# @leet start
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums) 
        map = [False for _ in range(n+1)]
        
        for num in nums:
            map[num] = True
        
        for i in range(n+1):
            if not map[i]:
                return i
        return 0
# @leet end
