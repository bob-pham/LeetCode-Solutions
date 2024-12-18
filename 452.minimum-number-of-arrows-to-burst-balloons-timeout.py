# @leet start
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key=lambda x : x[0])
        intervals = []

        for point in points:
            if point in intervals:
                continue
            p_left, p_right = point
            found = False
            for i in range(len(intervals)):
                i_left, i_right = intervals[i]
                start = max(p_left, i_left)
                end = min(p_right, i_right)

                if start <= end:
                    found = True
                    intervals[i] = start, end
                    break

            if not found:
                intervals.append(point)

        return len(intervals)

# @leet end
