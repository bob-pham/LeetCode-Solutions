# @leet start
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        left = 0
        l = len(nums) - 1
        right = l

        while left < right:
            while left <= l and nums[left] % 2 == 0:
                left += 1

            while right >= 0 and nums[right] % 2 == 1:
                right -= 1

            if right <= left:
                break

            nums[left], nums[right] = nums[right], nums[left]

        return nums


# @leet end

