class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        
        if (k > 1):
            return ''.join(sorted(s))
        
        sm = s
        s = deque(s)
        smallest = 'z'
        
        for i in s:
            smallest = min(smallest, i)
        
        for i in range(len(s)):        
            while (smallest != s[0]):
                s.append(s.popleft())
            
            sm = min(sm, ''.join(s))
            s.append(s.popleft())
                
        return ''.join(sm)