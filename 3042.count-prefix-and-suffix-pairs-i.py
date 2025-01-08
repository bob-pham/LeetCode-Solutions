# @leet start
class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        l = len(words)
        result = 0
        for i in range(l):
            curr_word = words[i]
            for j in range(i + 1, l):
                other_word = words[j]
                if other_word.startswith(curr_word) and other_word.endswith(curr_word):
                    result += 1
        return result
# @leet end
