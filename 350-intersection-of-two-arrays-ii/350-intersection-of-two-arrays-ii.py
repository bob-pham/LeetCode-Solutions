class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        counts1 = {}
        counts2 = {}
        result = []

        for i in nums1:
            if i in counts1:
                counts1[i] += 1
            else:
                counts1[i] = 1
        
        for i in nums2:
            if i in counts2:
                counts2[i] += 1
            else:
                counts2[i] = 1

        for i in counts1:
            if i in counts2:
                result += [int(i)] * min(counts1[i], counts2[i])

        return result 
