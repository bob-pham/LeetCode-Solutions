# @leet start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        memo = [0 for _ in range(amount + 1)]
        memo[0] = 0

        for i in range(1, amount + 1):
            local = sys.maxsize
            for coin in coins:
                if i - coin >= 0:
                    local = min(local, memo[i - coin] + 1)
            memo[i] = local

        return -1 if memo[-1] == sys.maxsize else memo[-1]

        
# @leet end
