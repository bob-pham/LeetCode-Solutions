class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counts = {}
        result = -1
        
        for i in arr:
            if i not in counts:
                counts[i] = 1
            else:
                counts[i] += 1
        
        for i in counts:
            if i == counts[i]:
                result = max(i, result)
        
        return result
        