class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        
        total = sum(nums)
        length = len(nums)
        left = 0
        result = sys.maxsize
        result_index = 0
        
        for i in range(length):
            curr = nums[i]
            left += curr
            total -= curr

            if i == length - 1:
                curr = left/length
            else:
                curr = abs((left//(i+1)) - (total//(length-(i+1))))
            
            if curr < result:
                result = curr
                result_index = i

        return result_index