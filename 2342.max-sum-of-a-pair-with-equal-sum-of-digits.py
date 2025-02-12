# @leet start
class Solution:
    def digitSum(self, num):
        result = 0
        num = str(num)

        for n in num:
            result += int(n)

        return result


    def maximumSum(self, nums: List[int]) -> int:
        max_sum = -1

        digitSums = {}

        for n in nums:
            d_sum = self.digitSum(n)
            if d_sum not in digitSums:
                digitSums[d_sum] = []
            heappush(digitSums[d_sum], -n)
            
        for s in digitSums:
            h = digitSums[s]
            if len(h) < 2:
                continue
            a = heappop(h) * -1
            b = heappop(h) * -1
            max_sum = max(max_sum, b + a)

        # 491 482
        return max_sum
        
# @leet end
