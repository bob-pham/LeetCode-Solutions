class Solution:
    def frequencySort(self, s: str) -> str:
        counts = Counter(s)
        s = ''
        for key in sorted(counts, reverse=True, key=(lambda x : counts[x])):
            s += key * counts[key] 

        return s
        