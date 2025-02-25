# @leet start
import heapq
class TrieNode:
    def __init__(self):
        self.map = {}
        self.wordmap = {}

    def get(self, val):
        if val not in self.map:
            return None

        return self.map[val]

    def getWord(self, val):
        if val not in self.wordmap:
            return None

        return self.wordmap[val]

    def set(self, val, idx):
        v = val[idx]
        if v not in self.map:
            self.map[v] = TrieNode()
        if v not in self.wordmap:
            self.wordmap[v] = []

        if len(self.wordmap[v]) < 3:
            heapq.heappush(self.wordmap[v], MaxHeapStr(val))
        else:
            heapq.heappushpop(self.wordmap[v], MaxHeapStr(val))
        return self.map[v]

class Trie:
    def __init__(self):
        self.root = TrieNode()

class MaxHeapStr(str):
    def __init__(self, string): self.string = string
    def __lt__(self,other): return self.string > other.string
    def __eq__(self,other): return self.string == other.string


class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        trie = Trie()
        result = []

        for prod in products:
            curr = trie.root
            for i in range(0, len(prod)):
                next = curr.set(prod, i)
                curr = next

        curr = trie.root
        for c in searchWord:
            if curr == None:
                break

            words = curr.getWord(c)

            if words == None:
                break

            result.append(sorted(words, reverse=True))

            curr = curr.get(c)

        while len(result) < len(searchWord):
            result.append([])

        return result

        
# @leet end
