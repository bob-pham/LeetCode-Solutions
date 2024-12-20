# @leet start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def dfs(i, curr, total):
            if total == target:
                result.append(curr.copy())
                return
            elif i >= len(candidates):
                return
            elif total > target:
                return

            curr.append(candidates[i])
            dfs(i, curr, total + candidates[i])
            curr.pop()
            dfs(i + 1, curr, total)

        dfs(0, [], 0)
            
        return result
# @leet end
