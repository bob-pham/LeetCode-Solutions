# @leet start
class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        l = len(nums)
        diff_arr = [{} for _ in range(l)]
        result = 2

        for idx in range(1, l):
            my_val = nums[idx]
            my_diff_map = diff_arr[idx]

            for i in range(idx-1, -1, -1):
                val = nums[i]
                local_diff = my_val - val
                local_diff_map = diff_arr[i]

                init_val = 2
                if local_diff in local_diff_map:
                    init_val = max(init_val, local_diff_map[local_diff] + 1)
                if local_diff in my_diff_map:
                    init_val = max(init_val, my_diff_map[local_diff])

                my_diff_map[local_diff] = init_val

        for diff_map in diff_arr:
            for val in diff_map.values():
                result = max(result, val)

        return result
        
# @leet end
