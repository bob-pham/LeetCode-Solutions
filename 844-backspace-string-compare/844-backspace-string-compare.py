class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        sPoint = len(s) - 1
        tPoint = len(t) - 1
        
        while (sPoint >= 0 or tPoint >= 0):
            sDown = 0
            tDown = 0
            
            while (sPoint >= 0 and s[sPoint] == '#'):
                while (sPoint >= 0 and s[sPoint] == '#'):
                    sDown += 1
                    sPoint -= 1
                while (sDown > 0 and sPoint >= 0):
                    if (s[sPoint] != '#'):
                        sDown -= 1
                    else:
                        sDown += 1
                    sPoint -= 1
            
            while (tPoint >= 0 and t[tPoint] == '#'):
                while (tPoint >= 0 and t[tPoint] == '#'):
                    tDown += 1
                    tPoint -= 1
                while (tDown > 0 and tPoint >= 0):
                    if (t[tPoint] != '#'):
                        tDown -= 1
                    else:
                        tDown += 1
                    tPoint -= 1
            
            print(sPoint)
            print(tPoint)
            print()
            
            if (sPoint < 0 and tPoint < 0):
                return True
            
            if ((sPoint < 0 and tPoint >= 0) or (sPoint >= 0 and tPoint < 0) or s[sPoint] != t[tPoint]):
                return False
            
            sPoint -= 1
            tPoint -= 1
        
        return True
            