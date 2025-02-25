# @leet start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        result = ""

        for i in range(l):
            # Check regular string
            left, right = i - 1, i + 1
            curr = s[i]

            while left >= 0 and right < l:
                v_left, v_right = s[left], s[right]
                if v_left == v_right:
                    curr = v_left + curr + v_right
                else:
                    break

                left -= 1
                right += 1

            if len(curr) > len(result):
                result = curr

            if i + 1 < l and s[i] == s[i+1]:
                curr = s[i] + s[i+1]
                left, right = i - 1, i + 2
                while left >= 0 and right < l:
                    v_left, v_right = s[left], s[right]
                    if v_left == v_right:
                        curr = v_left + curr + v_right
                    else:
                        break
                    left -= 1
                    right += 1

                if len(curr) > len(result):
                    result = curr


        return result
# @leet end
