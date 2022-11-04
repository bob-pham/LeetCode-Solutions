class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        pairs = 0
        center = 0
        wordsF = {}
        length = len(words)
        
        for word in words:
            if word not in wordsF:
                wordsF[word] = 1
            else:
                wordsF[word] += 1
                
        print(wordsF)
            
        for key in wordsF.keys():
            temp = key[1] + key[0]
            if temp == key:
                if wordsF[key] % 2:
                    num = wordsF[key] - 1
                    wordsF[key] = 1
                else:
                    num = wordsF[key]
                    wordsF[key] = 0
                pairs += int(num / 2)
                
            elif temp in wordsF and wordsF[temp]:
                num = min(wordsF[key], wordsF[temp])
                wordsF[key] -= num
                wordsF[temp] -= num
                
                pairs += num
                
        for key in wordsF.keys():
            if wordsF[key] and key[0] == key[1]:
                center = 2
                break
                
    
        return (4 * pairs) + center

        
        