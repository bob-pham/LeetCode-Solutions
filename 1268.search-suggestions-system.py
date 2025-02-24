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
        if val not in self.map:
            return None

        return self.wordmap[val]

    def set(self, val, idx):
        v = val[idx]
        if v not in self.map:
            self.map[v] = TrieNode()
            self.wordmap[v] = []
        heapq.heappush(self.wordmap[v], val)
        return self.map[v]

class Trie:
    def __init__(self):
        self.root = TrieNode()


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
        for i, c in enumerate(searchWord):
            if curr == None:
                for _ in range(i, len(searchWord)):
                    result.append([])
                return result

            words = curr.getWord(c)

            if words == None:
                for _ in range(i, len(searchWord)):
                    result.append([])
                return result

            if len(words) <= 3:
                result.append(words)
            else:
                result.append([heapq.heappop(words) for _ in range(3)])

            curr = curr.get(c)

        return result

        
# @leet end
