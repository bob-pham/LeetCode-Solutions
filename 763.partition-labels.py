# @leet start
from collections import Counter

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        groups = []
        curr = 0
        counts = Counter(s)
        todo = set()

        for c in s:
            todo.add(c)
            counts[c] -= 1
            curr += 1

            if counts[c] == 0:
                todo.remove(c)

            if len(todo) == 0:
                groups.append(curr)
                curr = 0

        return groups

# @leet end
