# @leet start
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        elems = {}
        for i in nums:
            if i not in elems:
                elems[i] = 0
            elems[i] += 1

        vals = [(-v, k) for k,v in zip(elems.keys(), elems.values())]
        heapq.heapify(vals)

        result = []
        for i in range(k):
            result.append(heapq.heappop(vals)[1])

        return result

# @leet end
