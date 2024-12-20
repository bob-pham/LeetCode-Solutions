# @leet start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        result = 0
        intervals.sort(key=lambda x: (x[0], abs(x[1]-x[0])))
        print(intervals)

        left, right = intervals[0][0], intervals[0][1]

        for i in range(1, len(intervals)):
            v_left, v_right = intervals[i][0], intervals[i][1]
            start = max(left, v_left)
            end = min(right, v_right)

            if start < end:
                result += 1
                if right - left > v_right - v_left:
                    left, right = v_left, v_right
            else:
                left, right = v_left, v_right

        return result
# @leet end
