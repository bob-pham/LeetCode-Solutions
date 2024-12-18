# @leet start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map = {}
        
        for item in strs:
            key = str(sorted(item))
            if key in map:
                map[key].append(item)
            else:
                map[key] = [item]

        return list(map.values())


# @leet end
