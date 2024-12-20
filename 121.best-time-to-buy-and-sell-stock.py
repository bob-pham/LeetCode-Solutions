# @leet start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        global_min = prices[0]

        for price in prices:
            global_min = min(global_min, price)
            max_profit = max(max_profit, price - global_min)
        return max_profit
        
# @leet end
