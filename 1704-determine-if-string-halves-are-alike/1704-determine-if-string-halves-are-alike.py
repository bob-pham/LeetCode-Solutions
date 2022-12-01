class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        first = 0
        second = 0
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        
        for i in range(len(s) // 2):
            curr = s[i]
            if curr in vowels:
                first += 1
        
        for i in range((len(s) // 2), len(s)):
            curr = s[i]
            if curr in vowels:
                second += 1
        
        return first == second
                