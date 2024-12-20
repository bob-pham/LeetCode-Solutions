# @leet start
from collections import deque

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        global_max = 0
        curr_count = 0
        curr_char = s[0]
        l = len(s)
        swaps = k
        char_list = deque()
        
        for i in range(1, l):
            if s[i] == curr_char:
                curr_count += 1
            elif swaps > 0:
                curr_count += 1
                swaps -= 1
            else:
                while len(char_list) > 0 and char_list[0] == curr_char:
                    curr_count -= 1
                    char_list.popleft()

                if len(char_list) > 0:
                    char_list.popleft()

            char_list.append(curr_char)
            global_max = max(global_max, curr_count)
        
        return global_max



# @leet end
