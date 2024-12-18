# @leet start
from heapq import heappop, heappush, heapify


class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total = sum(stones)
        target = total // 2
        result = set()
        closest = -1

        if len(stones) == 1:
            return stones[0]

        for weight in stones:
            newResult = result.copy()
            for sums in result:
                newResult.add(sums + weight)
            newResult.add(weight)
            result = newResult

        for sums in result:
            if abs(sums - target) < abs(target - closest):
                closest = sums

        other_half = total - closest
        return abs(other_half - closest)


# @leet end

