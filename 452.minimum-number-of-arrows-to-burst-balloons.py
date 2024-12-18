# @leet start
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key=lambda x : x[0])
        arrows = 1

        end = points[0][1]

        for i in range(1, len(points)):
            p_start, p_end = points[i]
            if end < p_start:
                arrows += 1
                end = p_end
            else:
                end = min(end, p_end)

        return arrows
# @leet end
