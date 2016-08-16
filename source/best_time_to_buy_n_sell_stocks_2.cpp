/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
 However, you may not engage in multiple transactions at the same time
 (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        if (size <= 1)
        {
            return 0;
        }

        int profit=0;

        /*int start = prices[0];
        int profit=0;
        int end=-1;
        */

        for(int i =1; i< size; i++)
        {
            if (prices[i] > prices[i-1])
            {
                profit = profit + (prices[i]- prices[i-1]);
            }
        }

        /*for(int i =1; i< size; i++)
        {
            if (prices[i]> start)
            {
                if (prices[i] > end)
                {
                    end = prices[i];
                }
                else
                {
                    if (end > -1)
                    {
                        profit = profit + (end -start);
                    }
                    start = prices[i];
                    end = -1;
                }
            }
            else
            {
                int diff = end - start;
                if (diff > 0)
                {
                    profit = profit + diff;
                }
                start = prices[i];
                end = -1;
            }
        }

        if (end != -1)
        {
        profit = profit + (end - start);
        }
        */

        return profit;
    }
};
