# @leet start
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return max(nums)

        memo = [0 for _ in nums]
        for i in range(len(nums)):
            one, two = 0, 0
            if i - 2 >= 0:
                one = memo[i - 2]
            if i - 3 >= 0:
                two = memo[i - 3]

            memo[i] = nums[i] + max(one, two)

        return max(memo[-1], memo[-2])


# @leet end

