class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:

        length = len(cost)
        
        if (length <= 1):
            return 0
        
        for i in range (2, length):
            cost[i] += min(cost[i-1], cost[i-2])
                
        return min(cost[length-1], cost[length-2])