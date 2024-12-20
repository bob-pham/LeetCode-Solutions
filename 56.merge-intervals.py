# @leet start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        result = []

        left = intervals[0][0]
        right = intervals[0][1]

        for i in range(1, len(intervals)):
            v_left, v_right = intervals[i][0], intervals[i][1]

            start =  max(left, v_left)
            end = min(right, v_right)
            if start <= end:
                left = min(left, v_left)
                right = max(right, v_right)
            else:
                result.append([left, right])
                left = v_left
                right = v_right

        result.append([left, right])

        return result
        
# @leet end
