# @leet start
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        result = 0
        heapify(nums)

        while (nums[0] < k):
            a = heappop(nums)
            b = heappop(nums)
            heappush(nums, (2 * min(a,b)) + max(a,b))
            result += 1
        
        return result
        
# @leet end
