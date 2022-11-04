class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        result = 0
        wordsF = {}
        
        for word in words:
            if word not in wordsF:
                wordsF[word] = 1
            else:
                wordsF[word] +=1
                
        for key in wordsF.keys():
            temp = key[1] + key[0]
            if temp == key:
                if wordsF[key] % 2: 
                    num = wordsF[key] - 1
                    wordsF[key] = 1
                else:
                    num = wordsF[key]
                    wordsF[key] = 0
                result += int(num * 2)
                
            elif temp in wordsF and wordsF[temp]:
                num = min(wordsF[key], wordsF[temp])
                wordsF[key] -= num
                wordsF[temp] -= num
                
                result += num * 4
                
        for key in wordsF.keys():
            if wordsF[key] and key[0] == key[1]:
                result += 2
                break
                
    
        return result

        
        