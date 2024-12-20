# @leet start
from collections import deque
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        current_chars = set()
        q = deque()

        global_max = 0
        current_count = 0

        for letter in s:
            if letter in current_chars:
                while letter in current_chars:
                    current_chars.remove(q.popleft())
                    current_count -= 1

            current_chars.add(letter)
            q.append(letter)
            current_count += 1
            global_max = max(current_count, global_max)

        return global_max

# @leet end
