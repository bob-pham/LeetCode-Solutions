# @leet start
class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        result = 0

        count1 = Counter(nums1)
        count2 = Counter(nums2)

        for c in count1:
            cval = count1[c]
            for c2 in count2:
                cval2 = count2[c2]
                if cval * cval2 % 2 != 0:
                    result = result ^ (c ^ c2)

        return result ^ 0
        
# @leet end
