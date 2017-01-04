/*
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/
class Solution(object):
    def totalCoins(self, coins, start, sum, result, table):
        if sum in table:
            return table[sum]
        if sum == 0:
            return 0
        minima = float ("inf")
        for i in range(len(coins)):
            if (sum < coins[i]):
                return -1
            diff = sum - coins[i]
            k = self.totalCoins(coins, i, diff, result, table)
            if(k != -1 and minima > k + 1):
                minima = k + 1

        table[sum] = minima
        if minima == float("inf"):
            return -1
        return minima


    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        coins.sort()
        result = 0
        table = {}
        return self.totalCoins(coins, 0, amount, result, table)

        
