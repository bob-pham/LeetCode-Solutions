# @leet start
import heapq
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def createDist(x, y):
            return ((y ** 2) + (x ** 2), [x, y])

        heap = []
        result = []

        for point in points:
            x, y = point
            heapq.heappush(heap, createDist(x, y))

        for _ in range(k):
            result.append(heapq.heappop(heap)[1])

        return result
        
# @leet end
