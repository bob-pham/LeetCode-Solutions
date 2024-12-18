# @leet start
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letter_map = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        if digits == "":
            return []

        result = []
        for c in letter_map[digits[0]]:
            result.append(c)

        for i in range(1, len(digits)):
            new_result = []
            for c in letter_map[digits[i]]:
                for wrd in result:
                    new_result.append(wrd + c)
            result = new_result

        return result
# @leet end
