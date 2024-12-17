# @leet start
class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        sorted_items = sorted(items, key= lambda x: (x[0], x[1]))
        answer = []

        print(sorted_items)

        for q in queries:
            low = 0
            high = len(sorted_items) - 1
            mid = 0
            while low <= high:
                mid = (high + low) // 2
                if sorted_items[mid][0] < q:
                    low = mid + 1
                elif sorted_items[mid][0] > q:
                    high = mid - 1
                else:
                    break;

            if (sorted_items[mid][0] > q):
                notFound = True
                for i in range(mid, -1, -1):
                    if sorted_items[i][0] <= q:
                        answer.append(sorted_items[i][1])
                        notFound = False
                        break;

                if notFound:
                    answer.append(0)
            else:
                idx = mid
                while idx < len(sorted_items) and sorted_items[idx][0] <= q:
                    idx += 1
                answer.append(sorted_items[idx-1][1])

        return queries
# @leet end
