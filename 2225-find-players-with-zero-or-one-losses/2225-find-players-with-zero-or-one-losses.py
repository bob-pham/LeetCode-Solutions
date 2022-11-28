class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        loses = {}
        undefeated = []
        almost_undefeated = []
        
        for match in matches:
            loses[match[0]] = 0 if match[0] not in loses else loses[match[0]]
            loses[match[1]] = 1 if match[1] not in loses else loses[match[1]] + 1
        
        for i in loses:
            if loses[i] == 0:
                undefeated.append(i)
            elif loses[i] == 1:
                almost_undefeated.append(i)
        
        return (sorted(undefeated), sorted(almost_undefeated))