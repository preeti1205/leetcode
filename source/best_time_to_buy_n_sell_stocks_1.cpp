/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:

Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:

Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

//Recursive solution - divide and conquer - O(nlogn) - 9ms

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size= prices.size();
        if (size < 2) return 0;
        vector<int> subarray ;
        for(int i = 1; i< size; i++){
            subarray.push_back(prices[i]- prices[i-1]);
        }
        return max_subarray(0, size-2 , subarray);

    }

    int max_subarray(int low, int high, vector<int>& nums){
        if (low == high)
            return max(nums[low],0);
        int mid = (low +high)/2;
        int left_sum = max_subarray(low, mid, nums);
        int right_sum = max_subarray(mid+1, high, nums);
        int cross_sum = max_cross_subarray(low, mid, high, nums);
        if ((left_sum >= right_sum) && (left_sum >= cross_sum)) return left_sum;
        if ((left_sum <= right_sum) && (cross_sum <= right_sum)) return right_sum;
        else return cross_sum;

    }

    int max_cross_subarray(int low, int mid, int high, vector<int>& nums){
        int left_sum = INT_MIN, right_sum = INT_MIN;
        int sum = 0;
        for(int i = mid ; i >= low; i--){
            sum += nums[i];
            if(sum > left_sum) left_sum = sum;
        }
         sum = 0;
        for(int i = mid+1 ; i <= high; i++){
            sum += nums[i];
            if(sum > right_sum) right_sum = sum;
        }
        return left_sum + right_sum;

    }
};

// Two pointer Solution - 6ms
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size= prices.size();
        if (size < 2) return 0;
        int minimum= prices[0];
        int diff = 0;
        for(int i = 1; i < size; i++){
            minimum = min(minimum, prices[i]);
            diff = max(prices[i] - minimum, diff);
        }
        return diff;
    }
};
