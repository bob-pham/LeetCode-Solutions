# @leet start
from collections import Counter

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        counts = Counter(nums)
        keys = list(counts.keys())
        result = 0

        for i in range(len(keys)):
            key = keys[i]
            val = counts[key]
            for j in range(i, len(keys)):
                other_key = keys[j]
                local_sum = key + other_key
                if (lower <= local_sum and local_sum <= upper):
                    if (i == j):
                        result += (val * (val - 1)) // 2
                    else:
                        other_val = counts[other_key]
                        result += val * other_val
        
        return result


# @leet end
