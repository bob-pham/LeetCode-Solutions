class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        cows = 0
        letters = {}
        
        for i in range(len(secret)):
            sec = secret[i]
            gus = guess[i]

            if (gus == sec):
                bulls += 1
            else:
                if (sec in letters):
                    if (letters[sec] > 0):
                        cows += 1
                    letters[sec] -= 1
                else:
                    letters[sec] = -1
                                
                if (gus in letters):
                    if (letters[gus] < 0):
                        cows += 1
                    letters[gus] += 1
                else:
                    letters[gus] = 1
                        
        return str(bulls) + "A" + str(cows) + "B"