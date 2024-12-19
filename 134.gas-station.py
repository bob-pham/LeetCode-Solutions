# @leet start
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1

        l = len(gas)

        current = 0
        start = 0
        for i, (g,c) in enumerate(zip(gas, cost)):
            current += g - c
            if current < 0:
                current = 0
                start = i + 1 % l

        return start
        
# @leet end

