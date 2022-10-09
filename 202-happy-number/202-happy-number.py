class Solution:
    def isHappy(self, n: int) -> bool:
        
        visited = set()
        
        if n == 1:
            return True
        
        while (n != 1 and n not in visited):
            visited.add(n)
            digits = str(n)
            n = 0
            
            for i in digits:
                n += int(i)**2
            
            if n == 1:
                return True
        
        return False