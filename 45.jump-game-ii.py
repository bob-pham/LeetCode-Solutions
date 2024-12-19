# @leet start
class Solution:
    def jump(self, nums: List[int]) -> int:
        mono = [sys.maxsize for _ in nums]
        mono[0] = 0

        for idx, num in enumerate(nums):
            val = mono[idx]
            if val == sys.maxsize:
                continue

            val += 1
            for i in range(idx, min(idx + num + 1, len(nums))):
                mono[i] = min(mono[i], val)

        return mono[-1]
        
# @leet end
