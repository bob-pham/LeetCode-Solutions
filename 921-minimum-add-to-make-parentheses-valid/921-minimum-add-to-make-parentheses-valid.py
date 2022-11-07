class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = deque()
        result = 0
        
        for i in s:
            if i == '(':
                stack.append(i)
            else:
                if stack and stack[-1] == '(':
                    stack.pop()
                else:
                    result += 1
        
        result += len(stack)
                    
        return result
                    
        
        