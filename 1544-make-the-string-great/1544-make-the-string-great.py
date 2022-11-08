class Solution:
    def makeGood(self, s: str) -> str:
        
        letters = deque()
        
        letters.append(s[0])
        
        for i in range(1, len(s)):
            if (letters and letters[-1].lower() == s[i].lower() and letters[-1] != s[i]):
                letters.pop()
            else:
                letters.append(s[i])
        
        return ''.join(letters)
            