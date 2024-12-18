# @leet start
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransomCount = Counter(ransomNote)
        magazineCount = Counter(magazine)

        for letter in ransomCount:
            if letter not in magazineCount:
                return False
            if ransomCount[letter] > magazineCount[letter]:
                return False

        return True
# @leet end
