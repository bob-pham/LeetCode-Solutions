class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        x = {stones[0][0]}
        y = {stones[0][1]}
        
        res = 0
        cycles = 1
        
        while (stones):
            not_found = []
            for i in stones:
                if i[0] in x or i[1] in y:
                    x.add(i[0])
                    y.add(i[1])
                    res += 1
                else:
                    not_found.append(i)
            
            if len(not_found) == len(stones):
                cycles += 1
                x = {not_found[0][0]}
                y = {not_found[0][1]}
                
            stones = not_found
        
        return res - cycles