# @leet start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        l = len(nums)

        def dfs(i, curr, n):
            curr.append(nums[i])

            if len(curr) == l:
                result.append(curr.copy())
                curr.pop()
                return
            for idx in range(n):
                new_idx = (i + idx + 1) % l
                print(i, new_idx)
                dfs(new_idx, curr, n-1)
            curr.pop()

        for i in range(l):
            dfs(i, [], l-1)
        
        return result
# @leet end
